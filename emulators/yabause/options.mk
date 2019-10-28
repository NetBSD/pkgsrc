# $NetBSD: options.mk,v 1.8 2019/10/28 09:33:29 kamil Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.yabause
PKG_SUPPORTED_OPTIONS=	openal opengl sdl
PKG_OPTIONS_OPTIONAL_GROUPS=	GUI SDL
PKG_OPTIONS_GROUP.GUI=		gtk qt
PKG_OPTIONS_GROUP.SDL=		sdl sdl2

PKG_SUGGESTED_OPTIONS=	qt sdl2

.include "../../mk/bsd.options.mk"

#.if !empty(PKG_OPTIONS:Mdoxygen)
#BUILD_DEPENDS+=	doxygen>=1.6.3:../../devel/doxygen
#.endif

.if !empty(PKG_OPTIONS:Mqt)
CONFIGURE_ENV+=	YAB_PORTS=qt
CMAKE_ARGS+=	-DYAB_PORTS=qt
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mgtk)
CONFIGURE_ENV+=	YAB_PORTS=gtk
CMAKE_ARGS+=	-DYAB_PORTS=gtk
CMAKE_ARGS+=	-DGTK2_GDKCONFIG_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.gtk2}/lib/gtk-2.0/include
CMAKE_ARGS+=	-DGTK2_GLIB_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.glib2}/include/glib/glib-2.0
CMAKE_ARGS+=	-DGTK2_GLIBCONFIG_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.glib2}/lib/glib-2.0/include
BUILDLINK_API_DEPENDS.gtkglext+=        gtkglext>=1.2.0nb4
.include "../../graphics/gtkglext/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mopenal)
.include "../../audio/openal-soft/buildlink3.mk"
CMAKE_ARGS+=	-DYAB_WANT_OPENAL=ON
.else
CMAKE_ARGS+=	-DYAB_WANT_OPENAL=OFF
.endif

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/freeglut/buildlink3.mk"
CMAKE_ARGS+=	-DYAB_WANT_OPENGL=ON
.else
CMAKE_ARGS+=	-DYAB_WANT_OPENGL=OFF
.endif

.if !empty(PKG_OPTIONS:Msdl)
.include "../../devel/SDL/buildlink3.mk"
CMAKE_ARGS+=	-DYAB_WANT_SDL1=ON
.elif !empty(PKG_OPTIONS:Msdl2)
.include "../../devel/SDL2/buildlink3.mk"
CMAKE_ARGS+=	-DYAB_WANT_SDL2=ON
.endif
