# $NetBSD: Makefile,v 1.83 2026/01/27 08:39:53 wiz Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
PKGREVISION=	9
COMMENT=	Wavelet transform of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_WAVELET=ON

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
