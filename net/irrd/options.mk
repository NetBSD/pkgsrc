# $NetBSD: options.mk,v 1.4 2019/11/03 11:45:38 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.irrd
PKG_SUPPORTED_OPTIONS=	pthreads
PKG_SUGGESTED_OPTIONS=	pthreads

.include "../../mk/bsd.options.mk"

# include support for pthreads
.if !empty(PKG_OPTIONS:Mpthreads)
CONFIGURE_ARGS+=        --enable-thread
PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"
.else
CONFIGURE_ARGS+=        --disable-thread
.endif
