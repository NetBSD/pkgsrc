# $NetBSD: options.mk,v 1.12 2022/06/07 16:47:33 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.harfbuzz
PKG_SUPPORTED_OPTIONS+=	doc
PKG_SUGGESTED_OPTIONS=	doc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc

.if !empty(PKG_OPTIONS:Mdoc)
MESON_ARGS+=	-Ddocs=enabled
BUILDLINK_API_DEPENDS.gtk-doc=	gtk-doc>=1.32nb9
.include "../../textproc/gtk-doc/buildlink3.mk"
PLIST.doc=	yes
.else
MESON_ARGS+=	-Ddocs=disabled
.endif
