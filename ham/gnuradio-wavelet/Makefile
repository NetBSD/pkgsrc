# $NetBSD: Makefile,v 1.75 2025/04/17 21:51:14 wiz Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
PKGREVISION=	1
COMMENT=	Wavelet transform of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_WAVELET=ON

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
