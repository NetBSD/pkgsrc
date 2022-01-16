# $NetBSD: Makefile,v 1.36 2022/01/16 18:06:26 tnn Exp $

PKGNAME=	gnuradio-fec-${VERSION}
COMMENT=	Forward Error Correction blocks, utilities, & examples of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_FEC=ON
CMAKE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include	"../../math/gsl/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
