# $NetBSD: options.mk,v 1.1 2013/06/09 22:36:12 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.spandsp
PKG_SUPPORTED_OPTIONS=	mmx sse tests
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmmx)
CONFIGURE_ARGS+=	--enable-mmx
.endif

.if !empty(PKG_OPTIONS:Msse)
CONFIGURE_ARGS+=	--enable-sse
.endif

.if !empty(PKG_OPTIONS:Mtests)
.include "../../textproc/libxml2/buildlink3.mk"
CFLAGS+=	-I${BUILDLINK_PREFIX.libxml2}/include/libxml2
.include "../../math/fftw/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.endif
