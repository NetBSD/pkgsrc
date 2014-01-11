# $NetBSD: options.mk,v 1.2 2014/01/11 21:11:53 khorben Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-browser
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
MAKE_FLAGS+=	CPPFLAGS=-DEMBEDDED
.endif
