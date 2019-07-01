# $NetBSD: Makefile,v 1.17 2019/07/01 04:08:23 ryoon Exp $

PKGNAME=	gnuradio-atsc-${VERSION}
PKGREVISION=	1
COMMENT=	Advanced Television Systems Committee, ATSC module of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_ATSC=ON
CMAKE_ARGS+=	-DENABLE_GR_FEC=ON

DEPENDS+=	gnuradio-fec-[0-9]*:../../ham/gnuradio-fec

PLIST_MINUS+=	fec
.include	"../../math/gsl/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
