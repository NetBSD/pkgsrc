# $NetBSD: options.mk,v 1.1 2016/02/26 15:52:08 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wiredtiger
PKG_SUPPORTED_OPTIONS=	bzip2 lz4 snappy zlib
PKG_SUGGESTED_OPTIONS=	snappy zlib

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		bzip2 lz4 snappy zlib

.if !empty(PKG_OPTIONS:Mbzip2)
.include "../../archivers/bzip2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-bzip2=on
PLIST.bzip2=		yes
.endif

.if !empty(PKG_OPTIONS:Mlz4)
.include "../../archivers/lz4/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-lz4=on
PLIST.lz4=		yes
.endif

.if !empty(PKG_OPTIONS:Msnappy)
.include "../../devel/snappy/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-snappy=on
PLIST.snappy=		yes
.endif

.if !empty(PKG_OPTIONS:Mzlib)
.include "../../devel/zlib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-zlib=on
PLIST.zlib=		yes
.endif
