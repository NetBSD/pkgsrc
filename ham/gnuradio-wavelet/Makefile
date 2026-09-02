# $NetBSD: Makefile,v 1.88 2026/09/02 19:03:01 wiz Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
PKGREVISION=	14
COMMENT=	Wavelet transform of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_WAVELET=ON

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
