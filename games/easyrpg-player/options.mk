# $NetBSD: options.mk,v 1.1 2018/12/21 16:57:35 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.easyrpg-player
PKG_SUPPORTED_OPTIONS=	freetype mpg123 libwildmidi vorbis opus sndfile speex
PKG_SUGGESTED_OPTIONS=	freetype mpg123 vorbis opus sndfile speex

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfreetype)
CONFIGURE_ARGS+=	--with-freetype
CONFIGURE_ARGS+=	--with-harfbuzz
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-freetype
CONFIGURE_ARGS+=	--without-harfbuzz
.endif

.if !empty(PKG_OPTIONS:Mmpg123)
CONFIGURE_ARGS+=	--with-libmpg123
.include "../../audio/mpg123/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-libmpg123
.endif

.if !empty(PKG_OPTIONS:Mlibwildmidi)
CONFIGURE_ARGS+=	--with-libwildmidi
.include "../../audio/libwildmidi/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-libwildmidi
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
CONFIGURE_ARGS+=	--with-oggvorbis
.include "../../audio/libvorbis/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-oggvorbis
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
CONFIGURE_ARGS+=	--with-oggvorbis
.include "../../audio/libvorbis/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-oggvorbis
.endif

.if !empty(PKG_OPTIONS:Mopus)
CONFIGURE_ARGS+=	--with-opus
.include "../../audio/libopus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-opus
.endif

.if !empty(PKG_OPTIONS:Msndfile)
CONFIGURE_ARGS+=	--with-libsndfile
.include "../../audio/libsndfile/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-libsndfile
.endif

.if !empty(PKG_OPTIONS:Mspeex)
CONFIGURE_ARGS+=	--with-speex
.include "../../audio/speexdsp/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-speex
.endif
