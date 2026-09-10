# $NetBSD: options.mk,v 1.2 2026/09/10 09:41:58 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libsoup3
PKG_SUPPORTED_OPTIONS=	gssapi
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgssapi)
.  include "../../mk/krb5.buildlink3.mk"
MESON_ARGS+=	-Dgssapi=enabled
.else
MESON_ARGS+=	-Dgssapi=disabled
.endif
