# $NetBSD: Makefile,v 1.36 2022/01/10 01:46:35 ryoon Exp $

PKGNAME=	gnuradio-dtv-${VERSION}
PKGREVISION=	1
COMMENT=	Various digital television standards of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_DTV=ON
CMAKE_ARGS+=	-DENABLE_GR_FEC=ON
CMAKE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	fec companion

.include	"../../ham/gnuradio-fec/buildlink3.mk"
.include	"../../math/gsl/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
