# $NetBSD: options.mk,v 1.1 2026/04/25 13:08:55 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libgusb
PKG_SUPPORTED_OPTIONS=	doc vapi
PKG_SUGGESTED_OPTIONS=	${PKG_SUPPORTED_OPTIONS}

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc vapi

#
# Build documentation
#
.if !empty(PKG_OPTIONS:Mdoc)
MESON_ARGS+=	-Ddocs=true
.  include "../../devel/py-gi-docgen/buildlink3.mk"
PLIST.doc=	yes
.else
MESON_ARGS+=	-Ddocs=false
.endif

#
# Generate Vala API file
#
.if !empty(PKG_OPTIONS:Mvapi)
MESON_ARGS+=    -Dvapi=true
.  include "../../lang/vala/buildlink3.mk"
PLIST.vapi=              yes
.else
MESON_ARGS+=    -Dvapi=false
.endif
