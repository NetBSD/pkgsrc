# $NetBSD: options.mk,v 1.3 2021/05/15 11:54:48 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ctrlproxy

PKG_SUPPORTED_OPTIONS=	gssapi

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgssapi)
.include "../../mk/krb5.buildlink3.mk"
.else
CONFIGURE_ARGS+=	ac_cv_path_KRB5_CONFIG="no"
.endif
