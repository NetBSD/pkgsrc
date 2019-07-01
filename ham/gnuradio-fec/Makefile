# $NetBSD: Makefile,v 1.17 2019/07/01 04:08:24 ryoon Exp $

PKGNAME=	gnuradio-fec-${VERSION}
PKGREVISION=	1
COMMENT=	Forward Error Correction blocks, utilities, & examples of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_FEC=ON

.include	"../../math/gsl/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
