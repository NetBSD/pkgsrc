# $NetBSD: options.mk,v 1.2 2019/11/02 15:38:01 rillig Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.kyotocabinet
PKG_SUPPORTED_OPTIONS=		zlib
PKG_OPTIONS_OPTIONAL_GROUPS=	codec
PKG_OPTIONS_GROUP.codec=	lzma lzo
PKG_SUGGESTED_OPTIONS=		zlib

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mzlib)
.include "../../devel/zlib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-zlib
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
.else
CONFIGURE_ARGS+=	--disable-zlib
.endif

.if !empty(PKG_OPTIONS:Mlzma)
.include "../../archivers/lzmalib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-lzma
.else
CONFIGURE_ARGS+=	--disable-lzma
.endif

.if !empty(PKG_OPTIONS:Mlzo)
.include "../../archivers/lzo/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-lzo
.else
CONFIGURE_ARGS+=	--disable-lzo
.endif
