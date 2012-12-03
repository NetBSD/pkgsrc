# $NetBSD: options.mk,v 1.6 2012/12/03 22:39:04 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.easytag
PKG_SUPPORTED_OPTIONS=	flac mp4v2 ogg speex wavpack
PKG_SUGGESTED_OPTIONS=	flac mp4v2 ogg speex wavpack

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mflac)
.  include "../../audio/flac/buildlink3.mk"
.  include "../../audio/libvorbis/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-flac
.else
CONFIGURE_ARGS+=	--disable-flac
.endif

.if !empty(PKG_OPTIONS:Mmp4v2)
.include "../../multimedia/mp4v2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mogg)
.  include "../../audio/libvorbis/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ogg
.else
CONFIGURE_ARGS+=	--disable-ogg
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
