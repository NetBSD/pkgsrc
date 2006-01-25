# $NetBSD: options.mk,v 1.3 2006/01/25 10:01:36 xtraeme Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mjpegtools
PKG_SUPPORTED_OPTIONS=	dv mjpegtools-simd
PKG_SUGGESTED_OPTIONS=	dv

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdv)
.  include "../../multimedia/libdv/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libdv
.else
CONFIGURE_ARGS+=	--disable-libdv
.endif

.if !empty(PKG_OPTIONS.mjpegtools-simd)
CONFIGURE_ARGS+=	--enable-simd-accel
.else
CONFIGURE_ARGS+=	--disable-simd-accel
.endif
