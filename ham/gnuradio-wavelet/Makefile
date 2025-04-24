# $NetBSD: Makefile,v 1.76 2025/04/24 14:14:45 wiz Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
PKGREVISION=	2
COMMENT=	Wavelet transform of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_WAVELET=ON

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
