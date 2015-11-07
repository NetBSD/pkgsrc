# $NetBSD: options.mk,v 1.2 2015/11/07 20:28:30 dholland Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ctrlproxy

PKG_SUPPORTED_OPTIONS=	ssl gssapi

.include "../../mk/bsd.options.mk"

###
### Build in SSL support via gnutls
###
.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/gnutls/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgssapi)
.include "../../mk/krb5.buildlink3.mk"
.else
CONFIGURE_ARGS+=	ac_cv_path_KRB5_CONFIG="no"
.endif
