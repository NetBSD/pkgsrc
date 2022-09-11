# $NetBSD: Makefile,v 1.41 2022/09/11 12:51:54 wiz Exp $

PKGNAME=	gnuradio-fec-${VERSION}
PKGREVISION=	2
COMMENT=	Forward Error Correction blocks, utilities, & examples of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_FEC=ON
CMAKE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include	"../../math/gsl/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
