# $NetBSD: Makefile,v 1.18 2020/05/06 14:04:42 adam Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
PKGREVISION=	4
COMMENT=	Wavelet transform of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_WAVELET=True

.include	"../../math/gsl/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
