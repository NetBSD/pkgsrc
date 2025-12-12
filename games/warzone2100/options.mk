# $NetBSD: options.mk,v 1.4 2025/12/12 10:25:08 triaxx Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.warzone2100
PKG_OPTIONS_REQUIRED_GROUPS=	backend
PKG_OPTIONS_GROUP.backend=	sdl3 qt5
PKG_SUGGESTED_OPTIONS=		sdl3

.include "../../mk/bsd.options.mk"

###
### Use SDL backend.
###
.if !empty(PKG_OPTIONS:Msdl3)
BUILDLINK_API_DEPENDS.SDL2+=	SDL3>=3.2.12
.include "../../devel/SDL3/buildlink3.mk"
.endif

###
### Use QT5 backend.
###
.if !empty(PKG_OPTIONS:Mqt5)
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif
