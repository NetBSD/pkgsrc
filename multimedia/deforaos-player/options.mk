# $NetBSD: options.mk,v 1.1 2012/12/17 00:54:23 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-player
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
MAKE_FLAGS+=	CPPFLAGS=-DEMBEDDED
.endif
