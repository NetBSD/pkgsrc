# $NetBSD: options.mk,v 1.5 2005/11/22 00:01:40 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.musicpd
PKG_SUPPORTED_OPTIONS=	aac audiofile flac iconv id3 libmikmod ogg
PKG_SUGGESTED_OPTIONS=	aac audiofile flac iconv id3 libmikmod ogg

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Maac)
.  include "../../audio/faad2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-faad=${BUILDLINK_PREFIX.faad2}
.else
CONFIGURE_ARGS+=	--disable-aac
.endif

.if !empty(PKG_OPTIONS:Maudiofile)
.  include "../../audio/libaudiofile/buildlink3.mk"
CONFIGURE_ARGS+=	--with-audiofile=${BUILDLINK_PREFIX.audiofile}
CONFIGURE_ENV+=		ac_cv_lib_iconv_iconv_open=yes
.else
CONFIGURE_ARGS+=	--disable-audiofile
.endif

.if !empty(PKG_OPTIONS:Mflac)
.  include "../../audio/flac/buildlink3.mk"
CONFIGURE_ARGS+=	--with-flac=${BUILDLINK_PREFIX.flac}
.else
CONFIGURE_ARGS+=	--disable-flac
.endif

.if !empty(PKG_OPTIONS:Miconv)
.  include "../../converters/libiconv/buildlink3.mk"
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
.else
CONFIGURE_ARGS+=	--disable-iconv
.endif

.if !empty(PKG_OPTIONS:Mid3)
.  include "../../audio/libid3tag/buildlink3.mk"
CONFIGURE_ARGS+=	--with-id3tag=${BUILDLINK_PREFIX.libid3tag}
.else
CONFIGURE_ARGS+=	--disable-id3
.endif

.if !empty(PKG_OPTIONS:Mlibmikmod)
.  include "../../audio/libmikmod/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libmikmod=${BUILDLINK_PREFIX.libmikmod}
.else
CONFIGURE_ARGS+=	--disable-libmikmod
.endif

.if !empty(PKG_OPTIONS:Mogg)
.  include "../../audio/libvorbis/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ogg=${BUILDLINK_PREFIX.libvorbis}
.else
CONFIGURE_ARGS+=	--disable-ogg
.endif

# when IPv6 support is enabled, mpd doesn't listen on an IPv4 address.
#.if !empty(PKG_OPTIONS:Minet6)
#CONFIGURE_ARGS+=	--enable-ipv6
#.else
CONFIGURE_ARGS+=	--disable-ipv6
#.endif
