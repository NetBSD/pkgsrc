# $NetBSD: Makefile,v 1.3 2015/09/01 04:14:54 mef Exp $

PKGNAME=	gnuradio-fec-${VERSION}
COMMENT=	Forward Error Correction blocks, utilities, & examples of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_FEC=ON

.include	"../../mk/bsd.pkg.mk"
