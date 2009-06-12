# $NetBSD: options.mk,v 1.12 2009/06/12 16:25:34 ahoka Exp $

# Global and legacy options

PKG_OPTIONS_VAR=	PKG_OPTIONS.ffmpeg
PKG_SUPPORTED_OPTIONS=	theora xvid faad faac x264
PKG_SUGGESTED_OPTIONS=	theora xvid x264
#PKG_OPTIONS_OPTIONAL_GROUPS=	aac-decoder
#PKG_OPTIONS_GROUP.aac-decoder=	faad faac

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.prefs.mk"

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
CONFIGURE_ARGS+=	--enable-libfaac \
			--enable-nonfree
.include "../../audio/faac/buildlink3.mk"
.endif

###
### SDL support
###
### You can build the frontend with SDL support enabled
###

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--enable-ffplay
PLIST.sdl=		yes
.include "../../devel/SDL/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ffplay
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
