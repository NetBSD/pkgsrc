# $NetBSD: Makefile,v 1.26 2025/02/12 06:45:13 ryoon Exp $

PKGNAME=	gnuradio-pdu-${VERSION}
PKGREVISION=	13
COMMENT=	Protocol Data Units for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"
# link to libgnuradio-fft.so.${PKGVERSON_NOREV}
.include "../../ham/gnuradio-core/buildlink3.mk"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_PDU=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include "../../mk/bsd.pkg.mk"
