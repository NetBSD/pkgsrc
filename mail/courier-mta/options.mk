# $NetBSD: options.mk,v 1.1.1.1 2006/04/28 18:10:21 jlam Exp $

# Global and legacy options

PKG_OPTIONS_VAR=	PKG_OPTIONS.courier-mta
PKG_SUPPORTED_OPTIONS=	courier-dsn courier-esmtp courier-local		\
			courier-uucp ldap
PKG_SUGGESTED_OPTIONS=	courier-dsn courier-esmtp courier-local		\
			courier-uucp

.include "../../mk/bsd.options.mk"

######################################################################
###
### delivery sender notification mail transport
###
.if !empty(PKG_OPTIONS:Mcourier-dsn)
COURIER_TRANSPORTS+=	dsn
PLIST_SRC+=		${PKGDIR}/PLIST.dsn

.  for _file_ in	dsndelayed.txt dsndelivered.txt dsnfailed.txt	\
			dsnfooter.txt dsnheader.txt dsnrelayed.txt	\
			dsnsubjectnotice.txt dsnsubjectwarn.txt module.dsn
CONF_FILES_PERMS+=	${EGDIR}/${_file_}				\
			${PKG_SYSCONFDIR}/${_file_:S/.dist$//}		\
				${COURIER_FILE_PERMS}
.  endfor
.endif

######################################################################
###
### ESMTP mail transport
###
.if !empty(PKG_OPTIONS:Mcourier-esmtp)
COURIER_TRANSPORTS+=	esmtp
PLIST_SRC+=		${PKGDIR}/PLIST.esmtp

RCD_SCRIPTS+=		courieresmtp courieresmtpmsa courieresmtps

OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/esmtpacceptmaildor.dir	\
				${COURIER_DIR_PERMS}
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/esmtppercentrelay.dir		\
				${COURIER_DIR_PERMS}

.  for _file_ in	esmtp.authpam esmtpd-msa.dist esmtpd-ssl.dist	\
			esmtpd.cnf esmtpd.dist module.esmtp
CONF_FILES_PERMS+=	${EGDIR}/${_file_}				\
			${PKG_SYSCONFDIR}/${_file_:S/.dist$//}		\
				${COURIER_FILE_PERMS}
.  endfor
CONF_FILES_PERMS+=	${EGDIR}/esmtpauthclient			\
			${PKG_SYSCONFDIR}/esmtpauthclient		\
				${COURIER_USER} ${COURIER_GROUP} 0600
.endif

######################################################################
###
### fax mail transport
###
### XXX This option should not be enabled until the dependencies for
### XXX generating and receiving faxes have all been sorted out, e.g.
### XXX mgetty+sendfax, netpbm, etc.
###
.if !empty(PKG_OPTIONS:Mcourier-fax)
USE_TOOLS+=		gs:run
COURIER_TRANSPORTS+=	fax
PLIST_SRC+=		${PKGDIR}/PLIST.fax

OWN_DIRS_PERMS+=	${COURIER_STATEDIR}/faxtmp			\
				${COURIER_USER} ${COURIER_GROUP} 0700

.  for _file_ in	faxcoverpage.tr.dist faxnotifyrc.dist module.fax
CONF_FILES_PERMS+=	${EGDIR}/${_file_}				\
			${PKG_SYSCONFDIR}/${_file_:S/.dist$//}		\
				${COURIER_FILE_PERMS}
.  endfor
CONF_FILES_PERMS+=	${EGDIR}/faxrc.dist ${PKG_SYSCONFDIR}/faxrc	\
				${COURIER_USER} ${COURIER_GROUP} 0640
.endif

######################################################################
###
### local mail tranport
###
.if !empty(PKG_OPTIONS:Mcourier-local)
COURIER_TRANSPORTS+=	local
PLIST_SRC+=		${PKGDIR}/PLIST.local

CONF_FILES_PERMS+=	${EGDIR}/module.local				\
			${PKG_SYSCONFDIR}/module.local			\
				${COURIER_FILE_PERMS}
.endif

######################################################################
###
### UUCP mail transport
###
.if !empty(PKG_OPTIONS:Mcourier-uucp)
COURIER_TRANSPORTS+=	uucp
UUCP_GROUP?=		daemon
PKG_GROUPS+=		${UUCP_GROUP}
PKG_USERS+=		uucp:${UUCP_GROUP}
PLIST_SRC+=		${PKGDIR}/PLIST.uucp

CONF_FILES_PERMS+=	${EGDIR}/module.uucp				\
			${PKG_SYSCONFDIR}/module.uucp			\
				${COURIER_FILE_PERMS}
.endif

.if empty(COURIER_TRANSPORTS)
PKG_FAIL_REASON+=	"[courier/options.mk] No mail transports specified."
.endif

######################################################################
###
### LDAP alias lookup support
###
.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldapaliasd
PLIST_SRC+=		${PKGDIR}/PLIST.ldap

RCD_SCRIPTS+=		courierldapaliasd
CONF_FILES_PERMS+=	${EGDIR}/ldapaliasrc.dist			\
			${PKG_SYSCONFDIR}/ldapaliasrc			\
				${COURIER_USER} ${COURIER_GROUP} 0640
.else
CONFIGURE_ARGS+=	--without-ldapaliasd
.endif
