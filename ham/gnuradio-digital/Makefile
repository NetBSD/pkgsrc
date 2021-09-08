# $NetBSD: Makefile,v 1.30 2021/09/08 21:05:13 nia Exp $

PKGNAME=	gnuradio-digital-${VERSION}
PKGREVISION=	1
COMMENT=	Digital related algorithms for GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"
# link to libgnuradio-fft.so.${PKGVERSON_NOREV}
.include       "../../ham/gnuradio-core/buildlink3.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_DIGITAL=ON
CMAKE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include	"../../mk/bsd.pkg.mk"
