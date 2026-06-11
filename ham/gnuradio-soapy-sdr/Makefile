# $NetBSD: Makefile,v 1.58 2026/06/11 07:17:12 wiz Exp $

PKGNAME=	gnuradio-soapy-sdr-${VERSION}
PKGREVISION=	11
COMMENT=	GNU Radio bindings for SoapySDR

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_SOAPY=ON

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../ham/soapy-sdr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
