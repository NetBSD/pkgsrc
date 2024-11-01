# $NetBSD: Makefile,v 1.67 2024/11/01 00:52:20 wiz Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
PKGREVISION=	7
COMMENT=	Wavelet transform of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_WAVELET=ON

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
