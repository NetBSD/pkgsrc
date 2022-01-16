# $NetBSD: options.mk,v 1.3 2022/01/16 14:32:01 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.easyrpg-player
PKG_SUPPORTED_OPTIONS=	alsa freetype mpg123 vorbis opus sndfile speex
PKG_SUGGESTED_OPTIONS=	freetype mpg123 vorbis opus sndfile speex

PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--with-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ENV+=		HAVE_ALSA_TRUE="\#"
CONFIGURE_ENV+=		HAVE_ALSA_FALSE=""
CONFIGURE_ARGS+=	--without-alsa
.endif

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
.include "../../audio/opusfile/buildlink3.mk"
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
CONFIGURE_ARGS+=	--with-libspeexdsp
.include "../../audio/speexdsp/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-libspeexdsp
.endif
