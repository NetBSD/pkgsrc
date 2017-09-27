# $NetBSD: options.mk,v 1.7 2017/09/27 13:49:38 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.SDL
PKG_SUPPORTED_OPTIONS=	aalib esound nas pulseaudio
PKG_SUGGESTED_OPTIONS=	esound nas pulseaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Maalib)
CONFIGURE_ARGS+=	--enable-video-aalib
.include "../../graphics/aalib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mesound)
CONFIGURE_ARGS+=	--enable-esd
.include "../../audio/esound/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-esd
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
