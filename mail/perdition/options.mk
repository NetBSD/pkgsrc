# $NetBSD: options.mk,v 1.4 2008/04/12 22:43:04 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.perdition
PKG_SUPPORTED_OPTIONS=	ssl pam
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		pam

###
### Build with PAM support.
###
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
PLIST.pam=		yes
.else
# prevent recognition of PAM in the base system
CONFIGURE_ENV+=		ac_cv_header_security_pam_appl_h=no
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
