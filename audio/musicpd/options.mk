# $NetBSD: options.mk,v 1.1 2004/11/25 20:16:52 xtraeme Exp $
#
# XXX Support for the following variables will be removed after the
# XXX pkgsrc-2004Q4 branch is released:
# XXX
# XXX MUSICPD_WITH_AAC
# XXX MUSICPD_WITH_AUDIOFILE
# XXX MUSICPD_WITH_FLAC
# XXX MUSICPD_WITH_ICONV
# XXX MUSICPD_WITH_ID3
# XXX MUSICPD_WITH_OGG

.if defined(MUSICPD_WITH_AAC) && !empty(MUSICPD_WITH_AAC:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	aac
.endif

.if defined(MUSICPD_WITH_AUDIOFILE) && \
    !empty(MUSICPD_WITH_AUDIOFILE:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	audiofile
.endif

.if defined(MUSICPD_WITH_FLAC) && !empty(MUSICPD_WITH_FLAC:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	flac
.endif

.if defined(MUSICPD_WITH_ICONV) && !empty(MUSICPD_WITH_ICONV:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	iconv
.endif

.if defined(MUSICPD_WITH_ID3) && !empty(MUSICPD_WITH_ID3:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	id3
.endif

.if defined(MUSICPD_WITH_OGG) && !empty(MUSICPD_WITH_OGG:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	ogg
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.musicpd
PKG_SUPPORTED_OPTIONS=	aac audiofile flac iconv id3 ogg
PKG_DEFAULT_OPTIONS+=	aac audiofile flac iconv id3 ogg

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

.if !empty(PKG_OPTIONS:Mogg)
.  include "../../audio/libvorbis/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ogg=${BUILDLINK_PREFIX.libvorbis}
.else
CONFIGURE_ARGS+=	--disable-ogg
.endif
