# $NetBSD: options.mk,v 1.5 2024/11/07 07:35:58 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gegl
PKG_SUPPORTED_OPTIONS=	svg jasper
PKG_SUGGESTED_OPTIONS=	svg

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	jasper svg

.if !empty(PKG_OPTIONS:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
PLIST.svg=	yes
PRINT_PLIST_AWK+=	{ if (/svg-load/) $$0 = "$${PLIST.svg}" $$0 }
.else
MESON_ARGS+=	-Dlibrsvg=disabled
.endif

.if !empty(PKG_OPTIONS:Mjasper)
.include "../../graphics/jasper/buildlink3.mk"
PLIST.jasper=	yes
PRINT_PLIST_AWK+=	{ if (/jp2-load/) $$0 = "$${PLIST.jasper}" $$0 }
.else
MESON_ARGS+=	-Djasper=disabled
.endif
