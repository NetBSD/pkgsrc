# $NetBSD: Makefile,v 1.86 2026/07/13 04:36:08 wiz Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
PKGREVISION=	12
COMMENT=	Wavelet transform of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_WAVELET=ON

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
