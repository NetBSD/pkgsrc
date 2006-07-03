# $NetBSD: options.mk,v 1.1.1.1 2006/07/03 09:42:30 jmmv Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.easytag-gtk2
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
.include "../../multimedia/mpeg4ip/buildlink3.mk"
# for mpeg4ip.h
CPPFLAGS+=		-DHAVE_GTK
.endif

.if !empty(PKG_OPTIONS:Mogg)
.  include "../../audio/libvorbis/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ogg
.else
CONFIGURE_ARGS+=	--disable-ogg
.endif
