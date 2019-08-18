# $NetBSD: options.mk,v 1.6 2019/08/18 08:13:30 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libsoup
PKG_SUPPORTED_OPTIONS=	gssapi
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgssapi)
.  include "../../mk/krb5.buildlink3.mk"
MESON_ARGS+=	-Dgssapi=true
MESON_ARGS+=	-Dkrb5_config=${KRB5_CONFIG}
.else
MESON_ARGS+=	-Dgssapi=false
.endif
