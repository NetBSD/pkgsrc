# $NetBSD: Makefile,v 1.50 2023/05/16 21:20:52 wiz Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
PKGREVISION=	4
COMMENT=	Wavelet transform of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_WAVELET=ON

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
