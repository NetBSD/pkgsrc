# $NetBSD: Makefile,v 1.9 2022/04/18 19:11:26 adam Exp $

PKGNAME=	gnuradio-soapy-sdr-${VERSION}
PKGREVISION=	2
COMMENT=	GNU Radio bindings for SoapySDR

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_SOAPY=ON
CMAKE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include	"../../ham/soapy-sdr/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
