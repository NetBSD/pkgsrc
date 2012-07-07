# $NetBSD: options.mk,v 1.6 2012/07/07 15:49:00 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mjpegtools
PKG_SUPPORTED_OPTIONS=	dv simd
PKG_SUGGESTED_OPTIONS=	dv
PKG_OPTIONS_LEGACY_OPTS+=	mjpegtools-simd:simd

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdv)
.  include "../../multimedia/libdv/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libdv
.else
CONFIGURE_ARGS+=	--disable-libdv
.endif

.if !empty(PKG_OPTIONS:Mmjpegtools-simd)
CONFIGURE_ARGS+=	--enable-simd-accel
.else
CONFIGURE_ARGS+=	--disable-simd-accel
.endif
