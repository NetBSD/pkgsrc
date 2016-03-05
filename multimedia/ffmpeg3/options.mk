# $NetBSD: options.mk,v 1.1 2016/03/05 08:52:23 ryoon Exp $

# Global and legacy options

PKG_OPTIONS_VAR=	PKG_OPTIONS.ffmpeg3
PKG_SUPPORTED_OPTIONS=	ass faac fdk-aac fontconfig freetype gnutls lame \
			libvpx opencore-amr openssl theora vorbis x264 x265 \
			xcb xvid
PKG_SUGGESTED_OPTIONS=	lame ass freetype fontconfig libvpx openssl \
			theora vorbis x264 xvid

# Add VDPAU if it is available
.include "../../multimedia/libvdpau/available.mk"
.if ${VDPAU_AVAILABLE} == "yes"
PKG_SUPPORTED_OPTIONS+= vdpau
PKG_SUGGESTED_OPTIONS+=	vdpau
.endif

# Add VAAPI if it is available
.include "../../multimedia/libva/available.mk"
.if ${VAAPI_AVAILABLE} == "yes"
PKG_SUPPORTED_OPTIONS+= vaapi
PKG_SUGGESTED_OPTIONS+=	vaapi
.endif

.include "../../mk/bsd.options.mk"

# Fontconfig
.if !empty(PKG_OPTIONS:Mfontconfig)
USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--enable-fontconfig
.include "../../fonts/fontconfig/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-fontconfig
.endif

# freetype option
.if !empty(PKG_OPTIONS:Mfreetype)
USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--enable-libfreetype
.include "../../graphics/freetype2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libfreetype
.endif

# ass option
.if !empty(PKG_OPTIONS:Mass)
USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--enable-libass
.include "../../multimedia/libass/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libass
.endif

# faac option
.if !empty(PKG_OPTIONS:Mfaac)
RESTRICTED=		This software may require the payment of patent royalties
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
CONFIGURE_ARGS+=	--enable-libfaac
CONFIGURE_ARGS+=	--enable-nonfree
.include "../../audio/faac/buildlink3.mk"
.endif

# Fraunhofer FDK AAC codec support
.if !empty(PKG_OPTIONS:Mfdk-aac)
RESTRICTED=		This software may require the payment of patent royalties
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
CONFIGURE_ARGS+=	--enable-libfdk_aac
CONFIGURE_ARGS+=	--enable-nonfree
.include "../../audio/fdk-aac/buildlink3.mk"
.endif

# GnuTLS support
.if !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--enable-gnutls
.include "../../security/gnutls/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gnutls
.endif

# opencore-amr option
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

# OpenSSL support
.if !empty(PKG_OPTIONS:Mopenssl)
CONFIGURE_ARGS+=	--enable-nonfree
CONFIGURE_ARGS+=	--enable-openssl
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-openssl
.endif

# OGG Theora support
.if !empty(PKG_OPTIONS:Mtheora)
CONFIGURE_ARGS+=	--enable-libtheora
.include "../../multimedia/libtheora/buildlink3.mk"
.endif

# OGG Vorbis support
.if !empty(PKG_OPTIONS:Mvorbis)
CONFIGURE_ARGS+=	--enable-libvorbis
.include "../../audio/libvorbis/buildlink3.mk"
.endif

# LAME MP3 encoder
.if !empty(PKG_OPTIONS:Mlame)
# "lame-3.98" isn't compatible with "ffmpeg" which breaks audio encoding.
BUILDLINK_ABI_DEPENDS.lame+= lame>=3.98.2nb1
CONFIGURE_ARGS+=	--enable-libmp3lame
.include "../../audio/lame/buildlink3.mk"
.endif

# XviD support
.if !empty(PKG_OPTIONS:Mxvid)
CONFIGURE_ARGS+=	--enable-libxvid
.include "../../multimedia/xvidcore/buildlink3.mk"
.endif

# x264 support
.if !empty(PKG_OPTIONS:Mx264)
# ABI change between 20090326 and 20100201
BUILDLINK_API_DEPENDS.x264-devel+=	x264-devel>=20111207
CONFIGURE_ARGS+=	--enable-libx264
.include "../../multimedia/x264-devel/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libx264
.endif

# x265 support
.if !empty(PKG_OPTIONS:Mx265)
CONFIGURE_ARGS+=	--enable-libx265
.include "../../multimedia/x265/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libx265
.endif

# VDPAU support
.if !empty(PKG_OPTIONS:Mvdpau)
CONFIGURE_ARGS+=	--enable-vdpau
.include "../../multimedia/libvdpau/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-vdpau
.endif

# VAAPI support
.if !empty(PKG_OPTIONS:Mvaapi)
CONFIGURE_ARGS+=	--enable-vaapi
.include "../../multimedia/libva/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-vaapi
.endif

# VPX support
.if !empty(PKG_OPTIONS:Mlibvpx)
CONFIGURE_ARGS+=	--enable-libvpx
.include "../../multimedia/libvpx/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libvpx
.endif

# X11 screen capture support using libxcb
.if !empty(PKG_OPTIONS:Mxcb)
CONFIGURE_ARGS+=	--enable-libxcb
CONFIGURE_ARGS+=	--enable-libxcb-shape
CONFIGURE_ARGS+=	--enable-libxcb-shm
CONFIGURE_ARGS+=	--enable-libxcb-xfixes
.include "../../x11/libxcb/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libxcb
.endif
