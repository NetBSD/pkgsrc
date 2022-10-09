# $NetBSD: Makefile,v 1.2 2022/10/09 07:56:10 adam Exp $

PKGNAME=	gnuradio-pdu-${VERSION}
COMMENT=	Protocol Data Units for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"
# link to libgnuradio-fft.so.${PKGVERSON_NOREV}
.include "../../ham/gnuradio-core/buildlink3.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_PDU=ON
CMAKE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include "../../mk/bsd.pkg.mk"
