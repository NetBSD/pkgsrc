# $NetBSD: Makefile,v 1.77 2025/05/18 19:31:21 gdt Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
PKGREVISION=	3
COMMENT=	Wavelet transform of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_WAVELET=ON

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
