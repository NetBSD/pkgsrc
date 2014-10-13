# $NetBSD: Makefile,v 1.1 2014/10/13 12:51:08 mef Exp $

PKGNAME=	gnuradio-atsc-${VERSION}
COMMENT=	Advanced Television Systems Committee, ATSC module of gnuradio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_ATSC=ON
CMAKE_ARGS+=	-DENABLE_GR_FEC=ON

DEPENDS+=	gnuradio-fec-[0-9]*:../../ham/gnuradio-fec

PLIST_MINUS+=	fec
.include	"../../mk/bsd.pkg.mk"
