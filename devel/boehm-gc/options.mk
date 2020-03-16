# $NetBSD: options.mk,v 1.6 2020/03/16 11:17:22 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.boehm-gc
PKG_SUPPORTED_OPTIONS=	threads
PKG_SUGGESTED_OPTIONS=	threads

.include "../../mk/bsd.options.mk"

###
### threads support
###
.if !empty(PKG_OPTIONS:Mthreads)
.include "../../mk/pthread.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-threads
.endif
