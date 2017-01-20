# $NetBSD: options.mk,v 1.1 2017/01/20 11:00:50 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.oce
PKG_SUPPORTED_OPTIONS=	oce-draw x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_SRC=	${PLIST_SRC_DFLT}

.if !empty(PKG_OPTIONS:Mx11)
CMAKE_ARGS+=	-DFREETYPE_INCLUDE_DIRS:PATH=${BUILDLINK_PREFIX.freetype2}/include
PLIST_SRC+=	${PKGDIR}/PLIST.x11
.  include "../../graphics/Mesa/buildlink3.mk"
.  include "../../graphics/freetype2/buildlink3.mk"
.else
CMAKE_ARGS+=	-DOCE_DISABLE_X11=ON
.endif

.if !empty(PKG_OPTIONS:Moce-draw)
.  if !empty(PKG_OPTIONS:Mx11)
CMAKE_ARGS+=	-DOCE_DRAW:BOOL=ON
PLIST_SRC+=	${PKGDIR}/PLIST.draw
.    include "../../lang/tcl/buildlink3.mk"
.    include "../../x11/tk/buildlink3.mk"
.  else
PKG_FAIL_REASON+=	"The 'oce-draw' option requires the 'x11' option"
.  endif
.endif
