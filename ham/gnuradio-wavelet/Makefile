# $NetBSD: Makefile,v 1.80 2025/09/27 09:57:24 wiz Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
PKGREVISION=	6
COMMENT=	Wavelet transform of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_WAVELET=ON

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
