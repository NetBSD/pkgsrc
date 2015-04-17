# $NetBSD: Makefile,v 1.2 2015/04/17 15:53:07 adam Exp $

PKGNAME=	gnuradio-atsc-${VERSION}
PKGREVISION=	1
COMMENT=	Advanced Television Systems Committee, ATSC module of gnuradio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_ATSC=ON
CMAKE_ARGS+=	-DENABLE_GR_FEC=ON

DEPENDS+=	gnuradio-fec-[0-9]*:../../ham/gnuradio-fec

PLIST_MINUS+=	fec
.include	"../../mk/bsd.pkg.mk"
