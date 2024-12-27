# $NetBSD: Makefile,v 1.72 2024/12/27 08:20:05 wiz Exp $

PKGNAME=	gnuradio-digital-${VERSION}
PKGREVISION=	11
COMMENT=	Digital related algorithms for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"
# link to libgnuradio-fft.so.${PKGVERSON_NOREV}
.include "../../ham/gnuradio-core/buildlink3.mk"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_DIGITAL=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include "../../mk/bsd.pkg.mk"
