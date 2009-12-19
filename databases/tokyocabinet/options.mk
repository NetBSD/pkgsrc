# $NetBSD: options.mk,v 1.1 2009/12/19 12:56:45 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.tokyocabinet
PKG_SUPPORTED_OPTIONS=	zlib bzip2
PKG_OPTIONS_OPTIONAL_GROUPS=	codec
PKG_OPTIONS_GROUP.codec=	lzma lzo
PKG_SUGGESTED_OPTIONS=	zlib bzip2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mzlib)
.include "../../devel/zlib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-zlib
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
.else
CONFIGURE_ARGS+=	--disable-zlib
.endif

.if !empty(PKG_OPTIONS:Mbzip2)
.include "../../archivers/bzip2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-bzip
CONFIGURE_ARGS+=	--with-bzip=${BUILDLINK_PREFIX.bzip2}
.else
CONFIGURE_ARGS+=	--disable-bzip
.endif

.if !empty(PKG_OPTIONS:Mlzma)
.include "../../archivers/lzmalib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-exlzma
.else
CONFIGURE_ARGS+=	--disable-exlzma
.endif

.if !empty(PKG_OPTIONS:Mlzo)
.include "../../archivers/lzo/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-exlzo
.else
CONFIGURE_ARGS+=	--disable-exlzo
.endif
