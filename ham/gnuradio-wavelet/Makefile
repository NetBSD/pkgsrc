# $NetBSD: Makefile,v 1.62 2024/05/29 16:33:07 adam Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
PKGREVISION=	3
COMMENT=	Wavelet transform of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_WAVELET=ON

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
