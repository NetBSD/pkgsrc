# $NetBSD: options.mk,v 1.1 2005/06/07 21:23:04 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mjpegtools
PKG_SUPPORTED_OPTIONS=	mjpegtools-cmov

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmjpegtools-cmov)
CONFIGURE_ARGS+=	--enable-cmov-extension
.else
CONFIGURE_ARGS+=	--disable-cmov-extension
.endif
