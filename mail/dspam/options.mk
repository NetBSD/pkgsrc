# $NetBSD: options.mk,v 1.1 2004/08/06 21:24:13 jlam Exp $

# Global and legacy options
.if defined(DSPAM_HOMEDIR_DOTFILES) || defined(DSPAM_USE_WEBMAIL) || \
    defined(DSPAM_SIGNATURE_ATTACHMENTS) || \
    defined(DSPAM_SIGNATURE_HEADERS) || defined(DSPAM_LARGESCALE) || \
    defined(DSPAM_VIRTUAL_USERS) || defined(DSPAM_CGI_GRAPHS) || \
    defined(DSPAM_CLIENT_COMPRESSION)
.  if !defined(PKG_OPTIONS.dspam)
.    if defined(DSPAM_HOMEDIR_DOTFILES) && \
        !empty(DSPAM_HOMEDIR_DOTFILES:M[Yy][Ee][Ss])
PKG_OPTIONS.dspam+=	dotfiles
.    endif
.    if defined(DSPAM_USE_WEBMAIL) && !empty(DSPAM_USE_WEBMAIL:M[Yy][Ee][Ss])
PKG_OPTIONS.dspam+=	webmail
.    endif
.    if defined(DSPAM_SIGNATURE_ATTACHMENTS) && \
        !empty(DSPAM_SIGNATURE_ATTACHMENTS:M[Yy][Ee][Ss])
PKG_OPTIONS.dspam+=	sig-attachment
.    endif
.    if defined(DSPAM_SIGNATURE_HEADERS) && \
        !empty(DSPAM_SIGNATURE_HEADERS:M[Yy][Ee][Ss])
PKG_OPTIONS.dspam+=	sig-headers
.    endif
.    if defined(DSPAM_LARGESCALE) && !empty(DSPAM_LARGESCALE:M[Yy][Ee][Ss])
PKG_OPTIONS.dspam+=	largescale
.    endif
.    if defined(DSPAM_VIRTUAL_USERS) && \
        !empty(DSPAM_VIRTUAL_USERS:M[Yy][Ee][Ss])
PKG_OPTIONS.dspam+=	virtualusers
.    endif
.    if defined(DSPAM_CGI_GRAPHS) && !empty(DSPAM_CGI_GRAPHS:M[Yy][Ee][Ss])
PKG_OPTIONS.dspam+=	graphs
.    endif
.    if defined(DSPAM_CLIENT_COMPRESSION) && \
        !empty(DSPAM_CLIENT_COMPRESSION:M[Yy][Ee][Ss])
PKG_OPTIONS.dspam+=	compress
.    endif
.  endif
.endif
.if defined(DSPAM_DELIVERY_AGENT) && !empty(DSPAM_DELIVERY_AGENT:Mcustom)
DSPAM_DELIVERY_AGENT:=	${DSPAM_DELIVERY_AGENT_ARGS}
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.dspam
PKG_SUPPORTED_OPTIONS=	compress dotfiles graphs largescale		\
			sig-attachment sig-headers virtualusers webmail
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
BUILD_DEPENDS+=		procmail-[0-9]*:../../mail/procmail
CONFIGURE_ARGS+=	--with-delivery-agent="${LOCALBASE}/bin/procmail"
.elif !empty(DSPAM_DELIVERY_AGENT:Mmaildrop)
BUILD_DEPENDS+=		maildrop-[0-9]*:../../mail/maildrop
CONFIGURE_ARGS+=	--with-delivery-agent="${LOCALBASE}/bin/maildrop"
.elif !empty(DSPAM_DELIVERY_AGENT)
CONFIGURE_ARGS+=	--with-delivery-agent=${DSPAM_DELIVERY_AGENT:Q}
.else
PKG_FAIL_REASON+=	"${PKGBASE}: unknown delivery agent \`${DSPAM_DELIVERY_AGENT}'"
.endif

###
### This is the backend database used to store the DSPAM signatures as
### well as other state information.  The recommended storage driver is
### "mysql", even for small installations.
### Possible: mysql, pgsql, bdb
### Default: bdb
###
DSPAM_STORAGE_DRIVER?=	bdb
BUILD_DEFS+=		DSPAM_STORAGE_DRIVER
MYSQL_PLIST_SUBST=	MYSQL="@comment "
PGSQL_PLIST_SUBST=	PGSQL="@comment "
.if empty(DSPAM_STORAGE_DRIVER:Mmysql)
PKG_OPTIONS:=		${PKG_OPTIONS:Ncompress}
.endif
.if empty(DSPAM_STORAGE_DRIVER:Mmysql) && empty(DSPAM_STORAGE_DRIVER:Mpgsql)
PKG_OPTIONS:=		${PKG_OPTIONS:Nvirtualusers}
.endif
.if !empty(DSPAM_STORAGE_DRIVER:Mmysql)
.  if !empty(PKG_OPTIONS:Mcompress)
CONFIGURE_ARGS+=	--enable-client-compression
.  endif
.  include "../../databases/mysql4-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-storage-driver=mysql_drv
CONFIGURE_ARGS+=	\
	--with-mysql-includes=${BUILDLINK_PREFIX.mysql-client}/include/mysql \
	--with-mysql-libraries=${BUILDLINK_PREFIX.mysql-client}/lib
MYSQL_PLIST_SUBST=	MYSQL=""
.elif !empty(DSPAM_STORAGE_DRIVER:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-storage-driver=pgsql_drv
CONFIGURE_ARGS+=	\
	--with-pgsql-includes=${PGSQL_PREFIX}/include/postgresql	\
	--with-pgsql-libraries=${PGSQL_PREFIX}/lib
PGSQL_PLIST_SUBST=	PGSQL=""
.elif !empty(DSPAM_STORAGE_DRIVER:Mbdb)
BDB_ACCEPTED=		db4 db3
.  include "../../mk/bdb.buildlink3.mk"
CONFIGURE_ARGS+=	--with-storage-driver=lib${BDB_TYPE}_drv
.else
PKG_FAIL_REASON+=	"${PKGBASE}: unknown storage driver \`${DSPAM_STORAGE_DRIVER}\'"
.endif
PLIST_SUBST+=		${MYSQL_PLIST_SUBST}
PLIST_SUBST+=		${PGSQL_PLIST_SUBST}

###
### Use of home directory dot file for opt-in/opt-out
###
.if !empty(PKG_OPTIONS:Mdotfiles)
CONFIGURE_ARGS+=	--enable-homedir-dotfiles
.endif

###
### This option will cause DSPAM to cease all writing of signatures
### and DSPAM headers to the message, and deliver the message in as
### pristine format as possible.  DO NOT use this switch unless the
### original message can be presented for retraining with the ORIGINAL
### HEADERS and NO MODIFICATIONS.
###
.if !empty(PKG_OPTIONS:Mwebmail)
CONFIGURE_ARGS+=	--enable-webmail
.endif

###
### Store DSPAM signatures as an attachment to the mail.  This option
### doesn't work correctly with mail clients, e.g. elm, that quote an
### embedded, forwarded message; it should only be used on networks
### where all clients can properly understand an embedded multipart
### message, e.g. Outlook, Evolution, etc., and forward the attachment
### as an attachment instead of quoted text.
###
.if !empty(PKG_OPTIONS:Msig-attachment)
CONFIGURE_ARGS+=	--enable-signature-attachments
.endif

###
### Store DSPAM signatures in the message header of the mail.
###
.if !empty(PKG_OPTIONS:Msig-headers)
CONFIGURE_ARGS+=        --enable-signature-headers
.endif

###
### Switch for large-scale implementation.  User data will be stored as
### $DSPAM_HOME/data/u/s/user instead of $DSPAM_HOME/data/user
###
.if !empty(PKG_OPTIONS:Mlargescale)
CONFIGURE_ARGS+=	--enable-large-scale
SUBST_STAGE.large=	pre-configure
SUBST_FILES.large=	cgi/dspam.cgi cgi/admin.cgi
SUBST_SED.large=	\
	-e "s|CONFIG{'LARGE_SCALE'}.*=.*0|CONFIG{'LARGE_SCALE'}	= 1|"
SUBST_MESSAGE.large=	"Enabling large-scale options in DSPAM."
.endif

###
### Tells DSPAM to create virtual user ids.  Use this if your users are
### not system users.
###
.if !empty(PKG_OPTIONS:Mvirtualusers)
CONFIGURE_ARGS+=	--enable-virtual-users
.endif

###
### Enable DSPAM's graph.cgi to produce graphs of spam statistics.
###
.if !empty(PKG_OPTIONS:Mgraphs)
DEPENDS+=	p5-GDGraph3d-[0-9]*:../../graphics/p5-GDGraph3d
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
