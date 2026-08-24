# $NetBSD: Makefile,v 1.60 2026/08/24 08:42:23 adam Exp $

PKGNAME=	gnuradio-soapy-sdr-${VERSION}
PKGREVISION=	13
COMMENT=	GNU Radio bindings for SoapySDR

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_SOAPY=ON

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../ham/soapy-sdr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
