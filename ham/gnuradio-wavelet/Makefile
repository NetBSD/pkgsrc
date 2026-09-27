# $NetBSD: Makefile,v 1.89 2026/09/27 11:37:07 tnn Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
PKGREVISION=	15
COMMENT=	Wavelet transform of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_WAVELET=ON

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
