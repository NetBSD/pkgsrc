# $NetBSD: options.mk,v 1.1 2016/09/09 15:40:17 scole Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.squashfs
PKG_SUPPORTED_OPTIONS=	zlib lz4 lzo xz xattr
PKG_SUGGESTED_OPTIONS=	zlib lzo xz

.include "../../mk/bsd.options.mk"

# XXX any other OS support xattr?
.if ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS+=	xattr
.endif

.if empty(PKG_OPTIONS:Mzlib) && \
    empty(PKG_OPTIONS:Mlz4) && \
    empty(PKG_OPTIONS:Mlzo) && \
    empty(PKG_OPTIONS:Mxz)
PKG_FAIL_REASON=	"need at least one compression algorithm selected"
.endif

.if !empty(PKG_OPTIONS:Mzlib)
.include "../../devel/zlib/buildlink3.mk"
BUILD_MAKE_FLAGS+=	GZIP_SUPPORT=1
.endif

.if !empty(PKG_OPTIONS:Mlz4)
.include "../../archivers/lz4/buildlink3.mk"
BUILD_MAKE_FLAGS+=	LZ4_SUPPORT=1
.endif

.if !empty(PKG_OPTIONS:Mlzo)
.include "../../archivers/lzo/buildlink3.mk"
BUILD_MAKE_FLAGS+=	LZO_SUPPORT=1
.endif

.if !empty(PKG_OPTIONS:Mxz)
.include "../../archivers/xz/buildlink3.mk"
BUILD_MAKE_FLAGS+=	XZ_SUPPORT=1
.endif

.if !empty(PKG_OPTIONS:Mxattr)
BUILD_MAKE_FLAGS+=	XATTR_SUPPORT=1
.endif
