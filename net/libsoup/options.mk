# $NetBSD: options.mk,v 1.7 2019/10/10 12:43:28 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libsoup
PKG_SUPPORTED_OPTIONS=	gssapi
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgssapi)
.  include "../../mk/krb5.buildlink3.mk"
MESON_ARGS+=	-Dgssapi=enabled
MESON_ARGS+=	-Dkrb5_config=${KRB5_CONFIG}
.else
MESON_ARGS+=	-Dgssapi=disabled
.endif
