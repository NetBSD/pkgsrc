# $NetBSD: options.mk,v 1.3 2013/01/27 00:15:03 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vic
PKG_SUPPORTED_OPTIONS=		inet6 # vic-gpl
PKG_SUGGESTED_OPTIONS=		inet6 # vic-gpl

.include "../../mk/bsd.options.mk"

## IPv6 support
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

## mpeg4+x264 support (ffmpeg)

.if !empty(PKG_OPTIONS:Mvic-gpl)
CONFIGURE_ARGS+=	--enable-gpl
CONFIGURE_ARGS+=	--disable-ffmpeg-co
CONFIGURE_ARGS+=	--disable-x264-co
CONFIGURE_ARGS+=	--with-ffmpeginc=${BUILDLINK_PREFIX.ffmpeg}/include
CONFIGURE_ARGS+=	--with-ffmpeglib=${BUILDLINK_PREFIX.ffmpeg}/lib
.include "../../multimedia/ffmpeg/buildlink3.mk"

CONFIGURE_ARGS+=	--with-x264inc=${BUILDLINK_PREFIX.x264-devel}/include
CONFIGURE_ARGS+=	--with-x264lib=${BUILDLINK_PREFIX.x264-devel}/lib
.include "../../multimedia/x264-devel/buildlink3.mk"
.endif
