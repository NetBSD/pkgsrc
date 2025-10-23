# $NetBSD: Makefile,v 1.54 2025/10/23 20:37:52 wiz Exp $

PKGNAME=	gnuradio-soapy-sdr-${VERSION}
PKGREVISION=	7
COMMENT=	GNU Radio bindings for SoapySDR

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_SOAPY=ON

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../ham/soapy-sdr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
