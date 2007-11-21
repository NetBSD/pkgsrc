# $NetBSD: options.mk,v 1.4 2007/11/21 21:47:25 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.easytag
PKG_SUPPORTED_OPTIONS=	flac mpeg4ip ogg
PKG_SUGGESTED_OPTIONS=	flac mpeg4ip ogg

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
