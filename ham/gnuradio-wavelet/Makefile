# $NetBSD: Makefile,v 1.78 2025/08/30 22:45:40 wiz Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
PKGREVISION=	4
COMMENT=	Wavelet transform of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_WAVELET=ON

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
