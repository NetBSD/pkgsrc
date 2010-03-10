# $NetBSD: options.mk,v 1.25 2010/03/10 13:43:38 martti Exp $

.if defined(DSPAM_DELIVERY_AGENT) && !empty(DSPAM_DELIVERY_AGENT:Mcustom)
DSPAM_DELIVERY_AGENT:=	${DSPAM_DELIVERY_AGENT_ARGS}
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.dspam
PKG_SUPPORTED_OPTIONS=	largescale homedir long-usernames graphs domainscale
PKG_SUPPORTED_OPTIONS+=	clamav syslog debug dspam-verbose-debug

PKG_OPTIONS_LEGACY_OPTS+=	verbose-debug:dspam-verbose-debug
PKG_OPTIONS_LEGACY_OPTS+=	virtualusers:dspam-virtualusers
PKG_OPTIONS_LEGACY_OPTS+=	preferences-extension:dspam-preferences-extension

###
### DSPAM_DELIVERY_AGENT is the tool called to to deliver messages.
###	It can either be "procmail", "maildrop" or the path to a
###	command (and arguments) used for local mail delivery.  Set this
###	to the path to the sendmail binary to reinject mail back into
###	the MTA instead of doing local delivery.
### Possible: procmail, maildrop or custom (e.g, /usr/sbin/sendmail)
### Default: procmail
###
DSPAM_DELIVERY_AGENT?=		procmail
BUILD_DEFS+=		DSPAM_DELIVERY_AGENT
.if !empty(DSPAM_DELIVERY_AGENT:Mprocmail)
DSPAM_DELIVERY_AGENT_BIN?=	${PREFIX}/bin/procmail
BUILD_DEPENDS+=		procmail-[0-9]*:../../mail/procmail
CONFIGURE_ARGS+=	--with-delivery-agent=${DSPAM_DELIVERY_AGENT_BIN:Q}
.elif !empty(DSPAM_DELIVERY_AGENT:Mmaildrop)
DSPAM_DELIVERY_AGENT_BIN?=	${PREFIX}/bin/maildrop
BUILD_DEPENDS+=		maildrop-[0-9]*:../../mail/maildrop
CONFIGURE_ARGS+=	--with-delivery-agent=${DSPAM_DELIVERY_AGENT_BIN:Q}
.elif !empty(DSPAM_DELIVERY_AGENT)
DSPAM_DELIVERY_AGENT_BIN?=	${DSPAM_DELIVERY_AGENT}
CONFIGURE_ARGS+=	--with-delivery-agent=${DSPAM_DELIVERY_AGENT_BIN:Q}
.else
PKG_FAIL_REASON+=	"${PKGBASE}: unknown delivery agent \`${DSPAM_DELIVERY_AGENT}'"
.endif

PLIST_VARS+=		hash mysql pgsql sqlite

###
### This is the backend database used to store the DSPAM signatures as
### well as other state information.  The recommended storage driver is
### "mysql", even for small installations.
### Possible: mysql, pgsql, sqlite, sqlite3 or hash
### Default: hash
###
DSPAM_STORAGE_DRIVER?=	hash
BUILD_DEFS+=		DSPAM_STORAGE_DRIVER
.if empty(DSPAM_STORAGE_DRIVER:Mmysql) && empty(DSPAM_STORAGE_DRIVER:Mpgsql)
PKG_OPTIONS:=		${PKG_OPTIONS:Ndspam-virtualusers}
PKG_OPTIONS:=		${PKG_OPTIONS:Ndspam-preferences-extension}
PKG_OPTIONS:=		${PKG_OPTIONS:Nldap}
.endif
.if !empty(DSPAM_STORAGE_DRIVER:Mhash)
CONFIGURE_ARGS+=	--with-storage-driver=hash_drv
PLIST.hash=		yes
.elif !empty(DSPAM_STORAGE_DRIVER:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-mysql4-initialization
CONFIGURE_ARGS+=	--with-storage-driver=mysql_drv
CONFIGURE_ARGS+=	\
	--with-mysql-includes=${BUILDLINK_PREFIX.mysql-client}/include/mysql \
	--with-mysql-libraries=${BUILDLINK_PREFIX.mysql-client}/lib
PLIST.mysql=		yes
.elif !empty(DSPAM_STORAGE_DRIVER:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-storage-driver=pgsql_drv
CONFIGURE_ARGS+=	\
	--with-pgsql-includes=${PGSQL_PREFIX}/include/postgresql	\
	--with-pgsql-libraries=${PGSQL_PREFIX}/lib
PLIST.pgsql=		yes
.elif !empty(DSPAM_STORAGE_DRIVER:Msqlite)
.  include "../../databases/sqlite/buildlink3.mk"
CONFIGURE_ARGS+=	--with-storage-driver=sqlite_drv
PLIST.sqlite=		yes
.elif !empty(DSPAM_STORAGE_DRIVER:Msqlite3)
.  include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-storage-driver=sqlite3_drv
PLIST.sqlite=		yes
.else
PKG_FAIL_REASON+=	"${PKGBASE}: unknown storage driver \\'${DSPAM_STORAGE_DRIVER}\\'"
.endif

# daemon mode only supports MySQL, PostgreSQL or hash
.if !empty(DSPAM_STORAGE_DRIVER:Mmysql) || \
    !empty(DSPAM_STORAGE_DRIVER:Mpgsql) || \
    !empty(DSPAM_STORAGE_DRIVER:Mhash)
.  if empty(MACHINE_PLATFORM:MNetBSD-1.*)
CONFIGURE_ARGS+=	--enable-daemon
.  endif
.endif

###
### The following are only available for mysql and pgsql backends.
###
.if !empty(DSPAM_STORAGE_DRIVER:Mmysql) || !empty(DSPAM_STORAGE_DRIVER:Mpgsql)
PKG_SUPPORTED_OPTIONS+=	dspam-preferences-extension dspam-virtualusers ldap
.endif

.include "../../mk/bsd.options.mk"

###
### Used to store user preferences in the backend instead of flat files
### (built-in method).
###
.if !empty(PKG_OPTIONS:Mdspam-preferences-extension)
CONFIGURE_ARGS+=	--enable-preferences-extension
.endif

###
### Tells DSPAM to create virtual user ids.  Use this if your users are
### not system users.
###
.if !empty(PKG_OPTIONS:Mdspam-virtualusers)
CONFIGURE_ARGS+=	--enable-virtual-users
.endif

###
### Enable LDAP support via libldap
###
.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--enable-ldap
.endif

###
### Use of home directory dot file for opt-in/opt-out
###
.if !empty(PKG_OPTIONS:Mhomedir)
CONFIGURE_ARGS+=	--enable-homedir
.endif

###
### Enable DSPAM's graph.cgi to produce graphs of spam statistics.
###
.if !empty(PKG_OPTIONS:Mgraphs)
DEPENDS+=		p5-GD-Graph3d-[0-9]*:../../graphics/p5-GD-Graph3d
.endif

###
### Switch for large-scale implementation.  User data will be stored as
### $DSPAM_HOME/data/u/s/user instead of $DSPAM_HOME/data/user
###
.if !empty(PKG_OPTIONS:Mlargescale)
CONFIGURE_ARGS+=	--enable-large-scale
.endif

###
### Support long usernames.
###
.if !empty(PKG_OPTIONS:Mlong-usernames)
CONFIGURE_ARGS+=	--enable-long-usernames
.endif

###
### Support for a domain scale implementation.
###
.if !empty(PKG_OPTIONS:Mdomainscale)
CONFIGURE_ARGS+=	--enable-domain-scale
.endif

###
### These are the flags used when invoking ps(1) to list all processes.
###
BUILD_DEFS+=		DSPAM_PSFLAGS
.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
DSPAM_PSFLAGS?=		-deaf
.else
DSPAM_PSFLAGS?=		aux
.endif

###
### Enables support for Clam Antivirus. DSPAM can interface directly with
### clamd to perform virus scanning and can be configured to react in
### different ways to viruses.
###
.if !empty(PKG_OPTIONS:Mclamav)
CONFIGURE_ARGS+=	--enable-clamav
.include "../../mail/clamav/buildlink3.mk"
.endif

###
### Enable syslog support, otherwise
### set flat logfile pathname for logging
###
.if !empty(PKG_OPTIONS:Msyslog)
CONFIGURE_ARGS+=	--enable-syslog
.else
CONFIGURE_ARGS+=	--disable-syslog
CONFIGURE_ARGS+=	--with-logfile=${DSPAM_LOGFILE}
.endif

###
### Enable debugging support for DSPAM.
### Don't enable this unless something needs testing!
###
.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

###
### Cause DSPAM produce verbose debug output and write them into
### LOGDIR/dspam.debug file. Implies '--enable-debug'.
### Never enable this for production builds !
###
.if !empty(PKG_OPTIONS:Mdspam-verbose-debug)
CONFIGURE_ARGS+=	--enable-verbose-debug
.endif
