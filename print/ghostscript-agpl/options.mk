# $NetBSD: options.mk,v 1.3 2013/12/27 16:42:46 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ghostscript
PKG_SUPPORTED_OPTIONS=	x11 debug fontconfig disable-compile-inits
PKG_SUGGESTED_OPTIONS=	x11 fontconfig

.include "../../mk/bsd.options.mk"

# (no_cidfmap)	when --disable-compile-inits selected,
#		cidfmap is renamed to cidfmap.dist
PLIST_VARS+=		no_cidfmap

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Mfontconfig)
.include "../../fonts/fontconfig/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-fontconfig
.endif

# Please note the same if condition is in post-extract: target in Makefile
.if !empty(PKG_OPTIONS:Mdisable-compile-inits)
CONFIGURE_ARGS+=	--disable-compile-inits
PLIST.no_cidfmap=	YES
.else
PLIST.cidfmap=		YES
.endif
