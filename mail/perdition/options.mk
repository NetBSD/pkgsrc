# $NetBSD: options.mk,v 1.2 2006/03/04 16:06:29 tv Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.perdition
PKG_SUPPORTED_OPTIONS=	ssl pam
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

###
### Build with PAM support.
###
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
PLIST_SUBST+=		PERDITION_HAVE_PAM=
.else
# prevent recognition of PAM in the base system
CONFIGURE_ENV+=		ac_cv_header_security_pam_appl_h=no
PLIST_SUBST+=		PERDITION_HAVE_PAM="@comment "
.endif

###
### Build with OpenSSL as the underlying crypto library.
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif
