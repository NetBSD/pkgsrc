# $NetBSD: options.mk,v 1.2 2026/11/16 17:37:44 vins Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.avfs
PKG_SUPPORTED_OPTIONS+=	debug fuse webdav zstd
PKG_SUGGESTED_OPTIONS+=	fuse zstd

PLIST_VARS+=	fuse

.include "../../mk/bsd.options.mk"

# Debug symbols
.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug=yes
.endif

# Compile the AVFS daemon for fuse
.if !empty(PKG_OPTIONS:Mfuse)
BUILDLINK_API_DEPENDS.fuse+=	fuse>=3.17
USE_FUSE3=		yes
.  include "../../mk/fuse.buildlink3.mk"
CONFIGURE_ARGS+=        --enable-fuse
PLIST.fuse=	yes
.else
CONFIGURE_ARGS+=        --disable-fuse
.endif

# Build zstd support
.if !empty(PKG_OPTIONS:Mzstd)
.  include "../../archivers/zstd/buildlink3.mk"
CONFIGURE_ARGS+=        --with-zstd
.else
CONFIGURE_ARGS+=        --without-zstd
.endif

# Build the DAV module (requires libneon)
.if !empty(PKG_OPTIONS:Mwebdav)
.  include "../../www/neon/buildlink3.mk"
CONFIGURE_ARGS+=        --enable-dav
.else
CONFIGURE_ARGS+=        --enable-dav
.endif
