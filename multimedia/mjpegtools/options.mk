# $NetBSD: options.mk,v 1.2 2006/01/25 08:09:12 xtraeme Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mjpegtools
PKG_SUPPORTED_OPTIONS=	dv
PKG_SUGGESTED_OPTIONS=	dv

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdv)
.  include "../../multimedia/libdv/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libdv
.else
CONFIGURE_ARGS+=	--disable-libdv
.endif
