# $NetBSD: options.mk,v 1.1 2009/11/10 10:23:15 dogcow Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xjdic
PKG_SUPPORTED_OPTIONS=	xjdic-locale
PKG_SUGGESTED_OPTIONS=	xjdic-locale

.include "../../mk/bsd.options.mk"

#die die die

.if !empty(PKG_OPTIONS:Mxjdic-locale)
PATCH_SITES=	http://www.tzone.org/~vandry/xjdic/
PATCHFILES+=	xjdic-24.locale.patch
.endif
