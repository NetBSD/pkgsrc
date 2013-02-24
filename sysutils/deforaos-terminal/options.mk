# $NetBSD: options.mk,v 1.1 2013/02/24 15:48:28 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-terminal
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
MAKE_FLAGS+=	CPPFLAGS=-DEMBEDDED
.endif
