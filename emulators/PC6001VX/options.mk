# $NetBSD: options.mk,v 1.1 2018/12/22 16:06:30 tsutsui Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.PC6001VX
PKG_SUPPORTED_OPTIONS=	debug ffmpeg sdl2

# debug enables for debug monitor support, which can be disabled
# for low performance machines.
PKG_SUGGESTED_OPTIONS+=	debug
# ffmpeg is required for video capture support.
PKG_SUGGESTED_OPTIONS+=	ffmpeg
# SDL2 is required for joystick support.
PKG_SUGGESTED_OPTIONS+=	sdl2

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Mdebug)
QMAKE_ARGS+=	"DEFINES+=NOMONITOR"
.endif

.if !empty(PKG_OPTIONS:Mffmpeg)
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.else
QMAKE_ARGS+=	"DEFINES+=NOAVI"
.endif

.if !empty(PKG_OPTIONS:Msdl2)
.include "../../devel/SDL2/buildlink3.mk"
.else
QMAKE_ARGS+=	"DEFINES+=NOJOYSTICK"
.endif
