# $NetBSD: Makefile,v 1.87 2026/08/24 08:42:23 adam Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
PKGREVISION=	13
COMMENT=	Wavelet transform of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_WAVELET=ON

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
