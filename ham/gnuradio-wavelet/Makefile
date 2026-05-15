# $NetBSD: Makefile,v 1.84 2026/05/15 09:58:54 adam Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
PKGREVISION=	10
COMMENT=	Wavelet transform of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_WAVELET=ON

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
