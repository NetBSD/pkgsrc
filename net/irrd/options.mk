# $NetBSD: options.mk,v 1.3 2013/04/08 11:17:18 rodent Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.irrd
PKG_SUPPORTED_OPTIONS=  pthreads
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
