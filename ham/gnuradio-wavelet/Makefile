# $NetBSD: Makefile,v 1.59 2024/01/07 12:18:01 mef Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
COMMENT=	Wavelet transform of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_WAVELET=ON

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
