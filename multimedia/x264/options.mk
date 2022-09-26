# $NetBSD: options.mk,v 1.1 2022/09/26 17:00:21 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.x264
PKG_SUPPORTED_OPTIONS=	threads

.if !empty(X264_BUILD_THREADS_SUPPORT:M[Yy][Ee][Ss])
PKG_SUGGESTED_OPTIONS+=	threads
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mthreads)
.  include "../../mk/pthread.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pthread
.endif
