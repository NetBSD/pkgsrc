# $NetBSD: options.mk,v 1.5 2018/07/27 10:23:12 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.boehm-gc
PKG_SUPPORTED_OPTIONS=	threads

PKG_SUGGESTED_OPTIONS.Darwin+=	threads
PKG_SUGGESTED_OPTIONS.SunOS+=	threads

.include "../../mk/bsd.options.mk"

###
### threads support
###
.if !empty(PKG_OPTIONS:Mthreads)
.include "../../mk/pthread.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-threads
.endif
