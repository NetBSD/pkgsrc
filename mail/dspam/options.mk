# $NetBSD: options.mk,v 1.7 2005/03/21 21:35:52 xtraeme Exp $

.if defined(DSPAM_DELIVERY_AGENT) && !empty(DSPAM_DELIVERY_AGENT:Mcustom)
DSPAM_DELIVERY_AGENT:=	${DSPAM_DELIVERY_AGENT_ARGS}
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.dspam
PKG_SUPPORTED_OPTIONS=	largescale homedir long-usernames graphs \
			domainscale

.include "../../mk/bsd.options.mk"

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
DSPAM_DELIVERY_AGENT_BIN?=	${LOCALBASE}/bin/procmail
BUILD_DEPENDS+=		procmail-[0-9]*:../../mail/procmail
CONFIGURE_ARGS+=	--with-delivery-agent=${DSPAM_DELIVERY_AGENT_BIN:Q}
.elif !empty(DSPAM_DELIVERY_AGENT:Mmaildrop)
DSPAM_DELIVERY_AGENT_BIN?=	${LOCALBASE}/bin/maildrop
BUILD_DEPENDS+=		maildrop-[0-9]*:../../mail/maildrop
CONFIGURE_ARGS+=	--with-delivery-agent=${DSPAM_DELIVERY_AGENT_BIN:Q}
.elif !empty(DSPAM_DELIVERY_AGENT)
DSPAM_DELIVERY_AGENT_BIN?=	${DSPAM_DELIVERY_AGENT}
CONFIGURE_ARGS+=	--with-delivery-agent=${DSPAM_DELIVERY_AGENT_BIN:Q}
.else
PKG_FAIL_REASON+=	"${PKGBASE}: unknown delivery agent \`${DSPAM_DELIVERY_AGENT}'"
.endif

###
### This is the backend database used to store the DSPAM signatures as
### well as other state information.  The recommended storage driver is
### "mysql", even for small installations.
### Possible: mysql, pgsql, bdb or sqlite
### Default: sqlite
###
DSPAM_STORAGE_DRIVER?=	sqlite
BUILD_DEFS+=		DSPAM_STORAGE_DRIVER
.if empty(DSPAM_STORAGE_DRIVER:Mmysql) && empty(DSPAM_STORAGE_DRIVER:Mpgsql)
PKG_OPTIONS:=		${PKG_OPTIONS:Nvirtualusers}
.endif
.if !empty(DSPAM_STORAGE_DRIVER:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-storage-driver=mysql_drv
CONFIGURE_ARGS+=	\
	--with-mysql-includes=${BUILDLINK_PREFIX.mysql-client}/include/mysql \
	--with-mysql-libraries=${BUILDLINK_PREFIX.mysql-client}/lib
MYSQL_PLIST_SUBST=	MYSQL=
.elif !empty(DSPAM_STORAGE_DRIVER:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-storage-driver=pgsql_drv
CONFIGURE_ARGS+=	\
	--with-pgsql-includes=${PGSQL_PREFIX}/include/postgresql	\
	--with-pgsql-libraries=${PGSQL_PREFIX}/lib
PGSQL_PLIST_SUBST=	PGSQL=
.elif !empty(DSPAM_STORAGE_DRIVER:Mbdb)
BDB_ACCEPTED=		db4 db3
.  include "../../mk/bdb.buildlink3.mk"
CONFIGURE_ARGS+=	--with-storage-driver=lib${BDB_TYPE}_drv
.elif !empty(DSPAM_STORAGE_DRIVER:Msqlite)
.  include "../../databases/sqlite/buildlink3.mk"
CONFIGURE_ARGS+=	--with-storage-driver=sqlite_drv
SQLITE_PLIST_SUBST=	SQLITE=
.else
PKG_FAIL_REASON+=	"${PKGBASE}: unknown storage driver \`${DSPAM_STORAGE_DRIVER}\'"
.endif

MYSQL_PLIST_SUBST?=	MYSQL="@comment "
PGSQL_PLIST_SUBST?=	PGSQL="@comment "
SQLITE_PLIST_SUBST?=	SQLITE="@comment "

PLIST_SUBST+=		${MYSQL_PLIST_SUBST}
PLIST_SUBST+=		${PGSQL_PLIST_SUBST}
PLIST_SUBST+=		${SQLITE_PLIST_SUBST}

###
### Only available for mysql and pgsql backends.
###
.if !empty(DSPAM_STORAGE_DRIVER:Mmysql) || !empty(DSPAM_STORAGE_DRIVER:Mpgsql)
PKG_SUPPORTED_OPTIONS+=	preferences-extension virtualusers
.endif

# Used to store user prefernces in the backend instead of flat files
# (built-in method)
.if !empty(PKG_OPTIONS:Mpreferences-extension)
CONFIGURE_ARGS+=	--enable-preferences-extension
.endif

###
### Tells DSPAM to create virtual user ids.  Use this if your users are
### not system users.
###
.if !empty(PKG_OPTIONS:Mvirtualusers)
CONFIGURE_ARGS+=	--enable-virtual-users
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
DEPENDS+=	p5-GDGraph3d-[0-9]*:../../graphics/p5-GDGraph3d
.endif

###
### Switch for large-scale implementation.  User data will be stored as
### $DSPAM_HOME/data/u/s/user instead of $DSPAM_HOME/data/user
###
.if !empty(PKG_OPTIONS:Mlargescale)
CONFIGURE_ARGS+=	--enable-large-scale
SUBST_CLASSES+=		large
SUBST_STAGE.large=	pre-configure
SUBST_FILES.large=	cgi/dspam.cgi cgi/admin.cgi
SUBST_SED.large=	\
	-e "s|CONFIG{'LARGE_SCALE'}.*=.*0|CONFIG{'LARGE_SCALE'}	= 1|"
SUBST_MESSAGE.large=	"Enabling large-scale option in DSPAM."
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
### EXPERIMENTAL:
### Support for neural networking, please take a look at the docs.
###
.if !empty(DSPAM_STORAGE_DRIVER:Mmysql)
PKG_SUPPORTED_OPTIONS+=	neural
.  if !empty(PKG_OPTIONS:Mneural)
CONFIGURE_ARGS+=	--enable-neural-networking
.  endif
.endif

###
### These are the flags used when invoking ps(1) to list all processes.
###
BUILD_DEFS+=		DSPAM_PSFLAGS
.if ${OPSYS} == "Linux"
DSPAM_PSFLAGS?=         -deaf
.else
DSPAM_PSFLAGS?=         aux
.endif
