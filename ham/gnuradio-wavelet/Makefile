# $NetBSD: Makefile,v 1.8 2017/08/24 20:03:25 adam Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
PKGREVISION=	2
COMMENT=	Wavelet transform of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_WAVELET=True

.include	"../../math/gsl/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
