# $NetBSD: options.mk,v 1.3 2008/02/20 10:12:04 xtraeme Exp $

# Global and legacy options

PKG_OPTIONS_VAR=	PKG_OPTIONS.ffmpeg
PKG_SUPPORTED_OPTIONS=	lame mmx vorbis sdl x264 theora xvid faad faac
PKG_SUGGESTED_OPTIONS=	lame vorbis faac sdl x264 theora
#PKG_OPTIONS_OPTIONAL_GROUPS=	aac-decoder
#PKG_OPTIONS_GROUP.aac-decoder=	faad faac


.include "../../mk/bsd.options.mk"

.include "../../mk/bsd.prefs.mk"

###
### MMX support
###

.include "../../mk/compiler.mk"

.if !empty(MACHINE_ARCH:Mi386)
.  if !empty(PKG_OPTIONS:Mmmx) && !empty(CC_VERSION:Mgcc*)
CFLAGS+=		-fomit-frame-pointer
.  else
CONFIGURE_ARGS+=	--disable-mmx
.  endif
.else
CONFIGURE_ARGS+=	--disable-mmx
.endif

###
### using lame option
###

.if !empty(PKG_OPTIONS:Mlame)
CONFIGURE_ARGS+= --enable-libmp3lame
.include "../../audio/lame/buildlink3.mk"
.endif

###
### using vorbis option
###

.if !empty(PKG_OPTIONS:Mvorbis)
CONFIGURE_ARGS+= --enable-libvorbis
CONFIGURE_ARGS+= --enable-libogg
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.endif

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
CONFIGURE_ARGS+=  --enable-libfaac
.include "../../audio/faac/buildlink3.mk"
.endif

###
### SDL support
###
### You can build the frontend with SDL support enabled
###

.if !empty(PKG_OPTIONS:Msdl)

CONFIGURE_ARGS+=	--enable-ffplay
PLIST_SRC+=		${PKGDIR}/PLIST.sdl

.include "../../devel/SDL/buildlink3.mk"
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
