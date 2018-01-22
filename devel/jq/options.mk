# $NetBSD: options.mk,v 1.1 2018/01/22 13:27:41 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.jq
PKG_SUPPORTED_OPTIONS=	oniguruma
PKG_SUGGESTED_OPTIONS=	oniguruma

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Moniguruma)
.include "../../textproc/oniguruma/buildlink3.mk"
.else
CONFIGURE_ARGS+=	ac_cv_lib_onig_onig_version=no
.endif
