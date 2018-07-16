# $NetBSD: Makefile,v 1.13 2018/07/16 07:50:04 mef Exp $

PKGNAME=	gnuradio-fec-${VERSION}
COMMENT=	Forward Error Correction blocks, utilities, & examples of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_FEC=ON

.include	"../../math/gsl/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
