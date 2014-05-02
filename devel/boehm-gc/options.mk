# $NetBSD: options.mk,v 1.3 2014/05/02 07:28:00 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.boehm-gc
PKG_SUPPORTED_OPTIONS=	threads

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PKG_SUGGESTED_OPTIONS=	threads
.endif

.include "../../mk/bsd.options.mk"

###
### threads support
###
.if !empty(PKG_OPTIONS:Mthreads)
.include "../../mk/pthread.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-threads
.endif
