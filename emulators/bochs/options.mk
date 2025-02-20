# $NetBSD: options.mk,v 1.1 2025/02/20 22:42:14 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bochs
PKG_SUPPORTED_OPTIONS+=	debug sdl x11

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS=	sdl x11
.else
PKG_SUGGESTED_OPTIONS=	sdl
.endif

PLIST_VARS+=		nox11 plugins x11 sdl

.include "../../mk/bsd.options.mk"

# Debugging features for the client operating systems. These options are
# not enabled by default because they can adversely impact performance.
.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--disable-plugins
CONFIGURE_ARGS+=	--enable-debugger
CONFIGURE_ARGS+=	--enable-iodebug
CONFIGURE_ARGS+=	--enable-x86-debugger
.else
PLIST.plugins=		yes
CONFIGURE_ARGS+=	--enable-plugins
.endif

.if !empty(PKG_OPTIONS:Mdebug) && !empty(PKG_OPTIONS:Mx11)
.include "../../x11/gtk3/buildlink3.mk"
.endif

# want SDL for sound and portable graphics
.if !empty(PKG_OPTIONS:Msdl)
PLIST.sdl=		yes
CONFIGURE_ARGS+=	--with-sdl
.  include "../../devel/SDL/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-sdl
.endif

.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=			yes
LIBS+=				-lX11
CONFIGURE_ARGS+=		--with-x
CONFIGURE_ARGS+=		--with-x11
BUILDLINK_DEPMETHOD.libXt?=	build
.  include "../../x11/libSM/buildlink3.mk"
.  include "../../x11/libX11/buildlink3.mk"
.  include "../../x11/libXpm/buildlink3.mk"
.  include "../../x11/libXrandr/buildlink3.mk"
.  include "../../x11/libXt/buildlink3.mk"
.else
PLIST.nox11=		yes
.  include "../../mk/curses.buildlink3.mk"
.  if ${OPSYS} == "NetBSD"
.    if ${CURSES_TYPE} == "curses"
GUI_LINK_OPTS_TERM=	-lcurses
.    endif
.  endif
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-x11
CONFIGURE_ARGS+=	--with-term
.endif
