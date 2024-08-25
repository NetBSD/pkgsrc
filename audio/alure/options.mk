# $NetBSD: options.mk,v 1.2 2024/08/25 06:18:22 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.alure
PKG_SUPPORTED_OPTIONS=	flac fluidsynth modplug mpg123 sndfile vorbis

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mflac)
CMAKE_CONFIGURE_ARGS+=	-DFLAC=ON
.include "../../audio/flac/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DFLAC=OFF
.endif

.if !empty(PKG_OPTIONS:Mfluidsynth)
CMAKE_CONFIGURE_ARGS+=	-DFLUIDSYNTH=ON
.include "../../audio/fluidsynth/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DFLUIDSYNTH=OFF
.endif

.if !empty(PKG_OPTIONS:Mmodplug)
CMAKE_CONFIGURE_ARGS+=	-DMODPLUG=ON
.include "../../audio/libmodplug/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DMODPLUG=OFF
.endif

.if !empty(PKG_OPTIONS:Msndfile)
CMAKE_CONFIGURE_ARGS+=	-DSNDFILE=ON
.include "../../audio/libsndfile/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DSNDFILE=OFF
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
CMAKE_CONFIGURE_ARGS+=	-DVORBIS=ON
.include "../../audio/libvorbis/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DVORBIS=OFF
.endif

.if !empty(PKG_OPTIONS:Mmpg123)
CMAKE_CONFIGURE_ARGS+=	-DMPG123=ON
.include "../../audio/mpg123/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DMPG123=OFF
.endif
