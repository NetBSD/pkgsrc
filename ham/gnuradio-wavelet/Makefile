# $NetBSD: Makefile,v 1.12 2018/08/16 18:54:55 adam Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
PKGREVISION=	1
COMMENT=	Wavelet transform of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_WAVELET=True

.include	"../../math/gsl/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
