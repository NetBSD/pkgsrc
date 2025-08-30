# $NetBSD: Makefile,v 1.51 2025/08/30 22:45:39 wiz Exp $

PKGNAME=	gnuradio-soapy-sdr-${VERSION}
PKGREVISION=	4
COMMENT=	GNU Radio bindings for SoapySDR

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_SOAPY=ON

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../ham/soapy-sdr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
