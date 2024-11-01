# $NetBSD: Makefile,v 1.40 2024/11/01 00:52:19 wiz Exp $

PKGNAME=	gnuradio-soapy-sdr-${VERSION}
PKGREVISION=	7
COMMENT=	GNU Radio bindings for SoapySDR

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_SOAPY=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include "../../ham/soapy-sdr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
