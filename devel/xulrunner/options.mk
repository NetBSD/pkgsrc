# $NetBSD: options.mk,v 1.1.1.1 2009/08/05 02:59:47 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xulrunner
PKG_SUPPORTED_OPTIONS=	debug mozilla-jemalloc

.include "../../mk/bsd.options.mk"

.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
PKG_SUGGESTED_OPTIONS+=	mozilla-jemalloc
.endif

.if !empty(PKG_OPTIONS:Mmozilla-jemalloc)
CONFIGURE_ARGS+=	--enable-jemalloc
.else
CONFIGURE_ARGS+=	--disable-jemalloc
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif
