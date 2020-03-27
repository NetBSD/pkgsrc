# $NetBSD: options.mk,v 1.2 2020/03/27 08:07:27 nia Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.warzone2100
PKG_OPTIONS_REQUIRED_GROUPS=	backend
PKG_OPTIONS_GROUP.backend=	sdl2 qt5
PKG_SUGGESTED_OPTIONS=		sdl2

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.options.mk"

###
### Use SDL backend.
###
.if !empty(PKG_OPTIONS:Msdl2)
.include "../../devel/SDL2/buildlink3.mk"
.endif

###
### Use QT5 backend.
###
.if !empty(PKG_OPTIONS:Mqt5)
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif
