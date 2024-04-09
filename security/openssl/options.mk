# $NetBSD: options.mk,v 1.14 2024/04/09 17:16:45 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openssl
PKG_SUPPORTED_OPTIONS=	zlib threads
PKG_SUGGESTED_OPTIONS=	threads

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mzlib)
CONFIGURE_ARGS+=	zlib
.include "../../devel/zlib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	no-zlib
.endif

.if !empty(PKG_OPTIONS:Mthreads)
CONFIGURE_ARGS+=	threads
.else
CONFIGURE_ARGS+=	no-threads
.endif
