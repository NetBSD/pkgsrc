# $NetBSD: options.mk,v 1.1 2018/09/30 22:29:32 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libmp3splt
PKG_SUPPORTED_OPTIONS+=	flac id3 mad pcre vorbis
PKG_SUGGESTED_OPTIONS+=	flac id3 mad pcre vorbis

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		flac
.if !empty(PKG_OPTIONS:Mflac)
.  include "../../audio/flac/buildlink3.mk"
PLIST.flac=		yes
.else
CONFIGURE_ARGS+=	--disable-flac
.endif

.if !empty(PKG_OPTIONS:Mid3)
.  include "../../audio/libid3tag/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-id3tag
.endif

PLIST_VARS+=		mad
.if !empty(PKG_OPTIONS:Mmad)
.  include "../../audio/libmad/buildlink3.mk"
PLIST.mad=		yes
.else
CONFIGURE_ARGS+=	--disable-mp3
.endif

.if !empty(PKG_OPTIONS:Mpcre)
.  include "../../devel/pcre/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pcre
.endif

PLIST_VARS+=		vorbis
.if !empty(PKG_OPTIONS:Mvorbis)
.  include "../../multimedia/libogg/buildlink3.mk"
.  include "../../audio/libvorbis/buildlink3.mk"
PLIST.vorbis=		yes
.else
CONFIGURE_ARGS+=	--disable-ogg
.endif
