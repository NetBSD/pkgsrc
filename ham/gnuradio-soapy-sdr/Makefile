# $NetBSD: Makefile,v 1.62 2026/09/27 11:37:07 tnn Exp $

PKGNAME=	gnuradio-soapy-sdr-${VERSION}
PKGREVISION=	15
COMMENT=	GNU Radio bindings for SoapySDR

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_SOAPY=ON

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../ham/soapy-sdr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
