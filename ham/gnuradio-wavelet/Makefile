# $NetBSD: Makefile,v 1.68 2024/11/01 12:53:06 wiz Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
PKGREVISION=	8
COMMENT=	Wavelet transform of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_WAVELET=ON

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
