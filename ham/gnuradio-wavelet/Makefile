# $NetBSD: Makefile,v 1.81 2025/10/23 20:37:53 wiz Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
PKGREVISION=	7
COMMENT=	Wavelet transform of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_WAVELET=ON

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
