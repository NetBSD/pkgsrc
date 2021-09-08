# $NetBSD: Makefile,v 1.48 2021/09/08 21:05:13 nia Exp $

PKGNAME=	gnuradio-trellis-${VERSION}
PKGREVISION=	1
COMMENT=	Trellis-based encoding and decoding algorithms for GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_TRELLIS=ON
CMAKE_ARGS+=	-DENABLE_GR_DIGITAL=ON
CMAKE_ARGS+=	-DENABLE_GRC=ON

DEPENDS+=	gnuradio-digital-[0-9]*:../../ham/gnuradio-digital
DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

PLIST_MINUS+=	companion digital

.include	"../../mk/bsd.pkg.mk"
