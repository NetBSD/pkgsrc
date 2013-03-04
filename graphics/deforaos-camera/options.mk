# $NetBSD: options.mk,v 1.1 2013/03/04 23:10:50 khorben Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-camera
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
MAKE_FLAGS+=	CPPFLAGS=-DEMBEDDED
.endif
