# $NetBSD: options.mk,v 1.1 2014/03/10 14:20:44 taca Exp $

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
.else
CONFIGURE_ARGS+=	--disable-threads
.endif
