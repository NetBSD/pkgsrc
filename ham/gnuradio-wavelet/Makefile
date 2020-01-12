# $NetBSD: Makefile,v 1.17 2020/01/12 20:20:25 ryoon Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
PKGREVISION=	3
COMMENT=	Wavelet transform of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_WAVELET=True

.include	"../../math/gsl/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
