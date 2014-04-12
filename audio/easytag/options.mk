# $NetBSD: options.mk,v 1.8 2014/04/12 06:45:31 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.easytag
PKG_SUPPORTED_OPTIONS=	flac ogg opus speex wavpack
PKG_SUGGESTED_OPTIONS=	flac ogg opus speex wavpack

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mflac)
.  include "../../audio/flac/buildlink3.mk"
.  include "../../audio/libvorbis/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-flac
.else
CONFIGURE_ARGS+=	--disable-flac
.endif

.if !empty(PKG_OPTIONS:Mogg)
.  include "../../audio/libvorbis/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ogg
.else
CONFIGURE_ARGS+=	--disable-ogg
.endif

.if !empty(PKG_OPTIONS:Mopus)
.  include "../../audio/libopus/buildlink3.mk"
.  include "../../audio/opusfile/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-opus
.else
CONFIGURE_ARGS+=	--disable-opus
.endif

.if !empty(PKG_OPTIONS:Mspeex)
.  include "../../audio/speex/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-speex
.else
CONFIGURE_ARGS+=	--disable-speex
.endif

.if !empty(PKG_OPTIONS:Mwavpack)
.  include "../../audio/wavpack/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-wavpack
.else
CONFIGURE_ARGS+=	--disable-wavpack
.endif
