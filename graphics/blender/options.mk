# $NetBSD: options.mk,v 1.1 2005/06/02 14:14:43 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.blender
PKG_SUPPORTED_OPTIONS=
# disabled these options; they ought to be re-instantiated one day
.if 0
PKG_SUPPORTED_OPTIONS+=	blender-exppython ogg openal vorbis
.endif
PKG_OPTIONS_LEGACY_VARS+=	BLENDER_USE_EXPPYTHON:blender-exppython
PKG_OPTIONS_LEGACY_VARS+=	BLENDER_USE_OGG:ogg
PKG_OPTIONS_LEGACY_VARS+=	BLENDER_USE_OPENAL:openal
PKG_OPTIONS_LEGACY_VARS+=	BLENDER_USE_VORBIS:vorbis

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mexppython)
CONFIGURE_ARGS+=	--enable-exppython
.else
CONFIGURE_ARGS+=	--disable-exppython
.endif

.if !empty(PKG_OPTIONS:Mogg)
CONFIGURE_ARGS+=	--with-ogg=${PREFIX}
.include "../../multimedia/libogg/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ogg --disable-oggtest
.endif

.if !empty(PKG_OPTIONS:Mopenal)
CONFIGURE_ARGS+=	--enable-openal
.include "../../audio/openal/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
CONFIGURE_ARGS+=	--with-vorbis=${PREFIX}
.include "../../audio/libvorbis/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-vorbis --disable-vorbistest
.endif
