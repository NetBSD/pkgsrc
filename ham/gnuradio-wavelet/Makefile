# $NetBSD: Makefile,v 1.45 2023/01/29 21:16:51 ryoon Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
PKGREVISION=	1
COMMENT=	Wavelet transform of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_WAVELET=ON

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
