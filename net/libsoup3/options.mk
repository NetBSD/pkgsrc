# $NetBSD: options.mk,v 1.1 2023/01/01 23:56:44 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libsoup3
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
