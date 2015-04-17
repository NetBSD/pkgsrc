# $NetBSD: Makefile,v 1.2 2015/04/17 15:53:08 adam Exp $

PKGNAME=	gnuradio-fec-${VERSION}
PKGREVISION=	1
COMMENT=	Forward Error Correction blocks, utilities, & examples of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_FEC=ON

.include	"../../mk/bsd.pkg.mk"
