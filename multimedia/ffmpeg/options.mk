# $NetBSD: options.mk,v 1.22 2011/08/12 06:14:27 mrg Exp $

# Global and legacy options

PKG_OPTIONS_VAR=	PKG_OPTIONS.ffmpeg
PKG_SUPPORTED_OPTIONS=	theora vorbis xvid faac x264 opencore-amr libvpx
PKG_SUGGESTED_OPTIONS=	theora vorbis xvid x264 libvpx
#PKG_OPTIONS_OPTIONAL_GROUPS=	aac-decoder
#PKG_OPTIONS_GROUP.aac-decoder=	faac

### Add vdpau if it is available
.include "../../multimedia/libvdpau/available.mk"
.if ${VDPAU_AVAILABLE} == "yes"
PKG_SUPPORTED_OPTIONS+= vdpau
PKG_SUGGESTED_OPTIONS+=	vdpau
.endif

.include "../../mk/bsd.options.mk"

###
### faac option
###
.if !empty(PKG_OPTIONS:Mfaac)
RESTRICTED=		This software may require the payment of patent royalties
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
CONFIGURE_ARGS+=	--enable-libfaac
CONFIGURE_ARGS+=	--enable-nonfree
.include "../../audio/faac/buildlink3.mk"
.endif

###
### opencore-amr option
###
.if !empty(PKG_OPTIONS:Mopencore-amr)
CONFIGURE_ARGS+=	--enable-libopencore-amrnb
CONFIGURE_ARGS+=	--enable-libopencore-amrwb

# "The OpenCORE external libraries are under the Apache License
# 2.0. That license is incompatible with the LGPL v2.1 and the GPL
# v2, but not with version 3 of those licenses. So to combine the
# OpenCORE libraries with FFmpeg, the license version needs to be
# upgraded by passing --enable-version3 to configure."
CONFIGURE_ARGS+=	--enable-version3
# TODO: LICENSE

.include "../../audio/opencore-amr/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libopencore-amrnb
CONFIGURE_ARGS+=	--disable-libopencore-amrwb
.endif

###
### OGG Theora support
###
.if !empty(PKG_OPTIONS:Mtheora)
CONFIGURE_ARGS+=	--enable-libtheora
.include "../../multimedia/libtheora/buildlink3.mk"
.endif

###
### OGG Vorbis support
###
.if !empty(PKG_OPTIONS:Mvorbis)
CONFIGURE_ARGS+=	--enable-libvorbis
.include "../../audio/libvorbis/buildlink3.mk"
.endif

###
### XviD support
###
.if !empty(PKG_OPTIONS:Mxvid)
CONFIGURE_ARGS+=	--enable-libxvid
.include "../../multimedia/xvidcore/buildlink3.mk"
.endif

###
### x264 support
###
.if !empty(PKG_OPTIONS:Mx264)
# ABI change between 20090326 and 20100201
BUILDLINK_API_DEPENDS.x264-devel+=	x264-devel>=20110707
#BUILDLINK_API_DEPENDS.x264-devel+=	x264-devel<20110102
CONFIGURE_ARGS+=	--enable-libx264
.include "../../multimedia/x264-devel/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libx264
.endif

###
### VDPAU support
###
.if !empty(PKG_OPTIONS:Mvdpau)
.include "../../multimedia/libvdpau/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-vdpau
.endif

.if !empty(PKG_OPTIONS:Mlibvpx)
CONFIGURE_ARGS+=	--enable-libvpx
.include "../../multimedia/libvpx/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libvpx
.endif
