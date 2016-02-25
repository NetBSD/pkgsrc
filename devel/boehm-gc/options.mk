# $NetBSD: options.mk,v 1.4 2016/02/25 12:12:47 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.boehm-gc
PKG_SUPPORTED_OPTIONS=	threads

PKG_SUGGESTED_OPTIONS.Darwin+=	threads

.include "../../mk/bsd.options.mk"

###
### threads support
###
.if !empty(PKG_OPTIONS:Mthreads)
.include "../../mk/pthread.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-threads
.endif
