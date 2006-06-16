# $NetBSD: options.mk,v 1.1 2006/06/16 18:43:18 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lsh
PKG_SUPPORTED_OPTIONS=	kerberos pam

.include "../../mk/bsd.options.mk"

###
### Kerberos password-checking support
###
.if !empty(PKG_OPTIONS:Mkerberos)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-kerberos
PLIST_SUBST+=		KERBEROS=
.else
CONFIGURE_ARGS+=	--disable-kerberos
PLIST_SUBST+=		KERBEROS="@comment "
.endif

###
### PAM password-checking support
###
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pam
PLIST_SUBST+=		PAM=
.else
CONFIGURE_ARGS+=	--disable-pam
PLIST_SUBST+=		PAM="@comment "
.endif
