# $NetBSD: options.mk,v 1.5 2012/03/08 09:49:26 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.easytag
PKG_SUPPORTED_OPTIONS=	flac mpeg4ip ogg speex wavpack
PKG_SUGGESTED_OPTIONS=	flac mpeg4ip ogg speex wavpack

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mflac)
.  include "../../audio/flac/buildlink3.mk"
.  include "../../audio/libvorbis/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-flac
.else
CONFIGURE_ARGS+=	--disable-flac
.endif

.if !empty(PKG_OPTIONS:Mmpeg4ip)
BUILDLINK_API_DEPENDS.libmp4v2+= libmp4v2>=1.6.1
.include "../../multimedia/libmp4v2/buildlink3.mk"
# for mpeg4ip.h
CPPFLAGS+=		-DHAVE_GTK
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
