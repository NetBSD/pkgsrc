# $NetBSD: Makefile,v 1.79 2025/09/21 18:15:08 wiz Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
PKGREVISION=	5
COMMENT=	Wavelet transform of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_WAVELET=ON

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
