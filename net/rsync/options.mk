# $NetBSD: options.mk,v 1.4 2022/12/29 00:47:40 sekiya Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rsync

PKG_SUPPORTED_OPTIONS=	zstd
PKG_SUGGESTED_OPTIONS=	zstd

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mzstd)
.include "../../archivers/zstd/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-zstd
.else
CONFIGURE_ARGS+=	--disable-zstd
.endif
