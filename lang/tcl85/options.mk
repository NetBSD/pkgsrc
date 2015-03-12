# $NetBSD: options.mk,v 1.2 2015/03/12 14:29:28 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tcl
PKG_SUPPORTED_OPTIONS=	threads debug
PKG_SUGGESTED_OPTIONS=	threads

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-symbols=mem
.endif

.if !empty(PKG_OPTIONS:Mthreads)
CONFIGURE_ARGS+=	--enable-threads
.include "../../mk/pthread.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-threads
.endif
