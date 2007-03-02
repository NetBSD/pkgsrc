# $NetBSD: options.mk,v 1.3 2007/03/02 12:05:32 grant Exp $

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
CONFIGURE_ARGS+=	--with-ssl-includes=${BUILDLINK_PREFIX.openssl}/include
CONFIGURE_ARGS+=	--with-ssl-libraries=${BUILDLINK_PREFIX.openssl}/lib
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif
