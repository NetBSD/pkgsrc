# $NetBSD: options.mk,v 1.1 2005/02/07 11:35:46 jlam Exp $

# Global and legacy options
.if defined(USE_OPENLDAP) && !empty(USE_OPENLDAP:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	ldap-compat
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.samba2
PKG_SUPPORTED_OPTIONS=	PAM cups ldap-compat
.include "../../mk/bsd.options.mk"

###
### Support PAM authentication.
###
.if !empty(PKG_OPTIONS:MPAM)
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
CONFIGURE_ARGS+=	--with-ldapsam
PLIST_SUBST+=		SAMBA_LDAP=""
.else   
PLIST_SUBST+=		SAMBA_LDAP="@comment "
MESSAGE_SRC=		${.CURDIR}/MESSAGE.smbpasswd
SMBPASSWD_FILE=		/dev/null ${SAMBA_PRIVATE}/smbpasswd		\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endif
