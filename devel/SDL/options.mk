# $NetBSD: options.mk,v 1.10 2020/01/20 21:13:16 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.SDL
PKG_SUPPORTED_OPTIONS=		aalib alsa nas pulseaudio
PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Maalib)
CONFIGURE_ARGS+=	--enable-video-aalib
.include "../../graphics/aalib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if !empty(PKG_OPTIONS:Mnas)
CONFIGURE_ARGS+=	--enable-nas
.include "../../audio/nas/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nas
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
# for some reason --enable-pulseaudio disables the
# configure check
#CONFIGURE_ARGS+=	--enable-pulseaudio
.include "../../audio/pulseaudio/buildlink3.mk"
.endif
