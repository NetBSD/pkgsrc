# $NetBSD: options.mk,v 1.3 2015/12/29 04:54:36 dholland Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libfishsound
PKG_SUPPORTED_OPTIONS=	doc valgrind
PKG_SUGGESTED_OPTIONS+=	flac speex vorbis
PKG_OPTIONS_NONEMPTY_SETS+=	codec
PKG_OPTIONS_SET.codec=		flac speex vorbis

PLIST_VARS+=		doc nodoc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	HAVE_DOXYGEN=no
PLIST.nodoc=		yes
.endif

.if !empty(PKG_OPTIONS:Mflac)
BUILDLINK_DEPMETHOD.flac=	build
.include "../../audio/flac/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-flac
.endif

.if !empty(PKG_OPTIONS:Mspeex)
.include "../../audio/speex/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-speex
.endif

.if !empty(PKG_OPTIONS:Mvalgrind)
BUILD_DEPENDS+=	valgrind-[0-9]*:../../devel/valgrind
CONFIGURE_ARGS+=	--enable-valgrind-testing
.else
CONFIGURE_ARGS+=	--disable-valgrind-testing
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
.include "../../audio/libvorbis/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-vorbis
.endif
