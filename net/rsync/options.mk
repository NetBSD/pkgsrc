# $NetBSD: options.mk,v 1.5 2022/12/31 09:10:15 sekiya Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rsync

PKG_SUPPORTED_OPTIONS=	acl zstd
PKG_SUGGESTED_OPTIONS=	acl zstd

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Macl)
CONFIGURE_ARGS+=       --disable-acl-support
.endif

.if !empty(PKG_OPTIONS:Mzstd)
.include "../../archivers/zstd/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-zstd
.else
CONFIGURE_ARGS+=	--disable-zstd
.endif
