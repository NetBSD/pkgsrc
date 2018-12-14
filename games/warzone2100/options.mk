# $NetBSD: options.mk,v 1.1 2018/12/14 17:29:32 triaxx Exp $
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
CONFIGURE_ARGS+=	--with-backend=sdl
.include "../../devel/SDL2/buildlink3.mk"
.endif

###
### Use QT5 backend.
###
.if !empty(PKG_OPTIONS:Mqt5)
CONFIGURE_ARGS+=	--with-backend=qt
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif
