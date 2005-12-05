# $NetBSD: options.mk,v 1.3 2005/12/05 23:55:07 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.blender
PKG_SUPPORTED_OPTIONS=
# disabled these options; they ought to be re-instantiated one day
.if 0
PKG_SUPPORTED_OPTIONS+=	blender-exppython ogg openal vorbis
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mexppython)
CONFIGURE_ARGS+=	--enable-exppython
.else
CONFIGURE_ARGS+=	--disable-exppython
.endif

.if !empty(PKG_OPTIONS:Mogg)
CONFIGURE_ARGS+=	--with-ogg=${PREFIX:Q}
.include "../../multimedia/libogg/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ogg --disable-oggtest
.endif

.if !empty(PKG_OPTIONS:Mopenal)
CONFIGURE_ARGS+=	--enable-openal
.include "../../audio/openal/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
CONFIGURE_ARGS+=	--with-vorbis=${PREFIX:Q}
.include "../../audio/libvorbis/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-vorbis --disable-vorbistest
.endif
