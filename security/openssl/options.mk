# $NetBSD: options.mk,v 1.15 2024/05/01 21:11:18 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openssl
PKG_SUPPORTED_OPTIONS=	zlib threads

.include "../../mk/bsd.fast.prefs.mk"

.if !${MACHINE_PLATFORM:MDarwin-*-powerpc*}
PKG_SUGGESTED_OPTIONS=	threads
.endif

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
