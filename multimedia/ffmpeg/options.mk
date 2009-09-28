# $NetBSD: options.mk,v 1.12.2.1 2009/09/28 08:08:31 spz Exp $

# Global and legacy options

PKG_OPTIONS_VAR=	PKG_OPTIONS.ffmpeg
PKG_SUPPORTED_OPTIONS=	theora xvid faad faac x264
PKG_SUGGESTED_OPTIONS=	theora xvid x264
#PKG_OPTIONS_OPTIONAL_GROUPS=	aac-decoder
#PKG_OPTIONS_GROUP.aac-decoder=	faad faac

.include "../../mk/bsd.options.mk"

###
### faad option
###

.if !empty(PKG_OPTIONS:Mfaad)
CONFIGURE_ARGS+=  --enable-libfaad
.include "../../audio/faad2/buildlink3.mk"
.endif

###
### faac option
###

.if !empty(PKG_OPTIONS:Mfaac)
RESTRICTED=		This software may require the payment of patent royalties
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
CONFIGURE_ARGS+=	--enable-libfaac \
			--enable-nonfree
.include "../../audio/faac/buildlink3.mk"
.endif

###
### OGG Theora support
###

.if !empty(PKG_OPTIONS:Mtheora)
CONFIGURE_ARGS+=  --enable-libtheora
.include "../../multimedia/libtheora/buildlink3.mk"
.endif

###
### XviD support
###

.if !empty(PKG_OPTIONS:Mxvid)
CONFIGURE_ARGS+=  --enable-libxvid
.include "../../multimedia/xvidcore/buildlink3.mk"
.endif

###
### x264 support
###

.if !empty(PKG_OPTIONS:Mx264)
BUILDLINK_API_DEPENDS.x264-devel+=	x264-devel>=20071218
CONFIGURE_ARGS+=  --enable-libx264
.include "../../multimedia/x264-devel/buildlink3.mk"
.endif
