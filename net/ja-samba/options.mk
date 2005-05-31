# $NetBSD: options.mk,v 1.3 2005/05/31 11:24:32 dillo Exp $

# Global and legacy options

PKG_OPTIONS_VAR=	PKG_OPTIONS.ja-samba
PKG_SUPPORTED_OPTIONS=	pam cups ldap
.include "../../mk/bsd.options.mk"

###
### Support PAM authentication.
###
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
.endif

###
### Native CUPS support for printing
###
.if !empty(PKG_OPTIONS:Mcups)
.  include "../../print/cups/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-cups
.endif

###
### Support Samba-2.x LDAP password and account databases.
###
.if !empty(PKG_OPTIONS:Mldap-compat)
.  include "../../databases/openldap/buildlink3.mk"
BUILD_DEFS+=		USE_OPENLDAP
CONFIGURE_ARGS+=	--with-ldapsam
PLIST_SUBST+=		SAMBA_LDAP=""
.else
PLIST_SUBST+=		SAMBA_LDAP="@comment "
MESSAGE_SRC=		${.CURDIR}/MESSAGE.common ${.CURDIR}/MESSAGE.smbpasswd
SMBPASSWD_FILE=		/dev/null ${SAMBA_PRIVATE}/smbpasswd		\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endif
