# $NetBSD: Makefile,v 1.1 2014/10/13 12:51:10 mef Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
COMMENT=	Wavelet transform of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_WAVELET=True

.include	"../../math/gsl/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
