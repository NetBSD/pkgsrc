# $NetBSD: Makefile,v 1.13 2018/12/13 19:52:04 adam Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
PKGREVISION=	2
COMMENT=	Wavelet transform of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_WAVELET=True

.include	"../../math/gsl/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
