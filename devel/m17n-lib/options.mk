# $NetBSD: options.mk,v 1.4 2010/07/21 13:11:11 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.m17n-lib
PKG_SUPPORTED_OPTIONS=	anthy x11 libthai
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11

.if !empty(PKG_OPTIONS:Manthy)
.include "../../inputmethod/anthy/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mx11)
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
BUILDLINK_API_DEPENDS.libotf+=	libotf>=0.9.11
.include "../../graphics/libotf/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
PLIST.x11=		yes
.else
CONFIGURE_ARGS+=	--without-gui
.endif

.if !empty(PKG_OPTIONS:Mlibthai)
.include "../../devel/libthai/buildlink3.mk"
.endif
