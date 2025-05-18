# $NetBSD: Makefile,v 1.50 2025/05/18 19:31:21 gdt Exp $

PKGNAME=	gnuradio-soapy-sdr-${VERSION}
PKGREVISION=	3
COMMENT=	GNU Radio bindings for SoapySDR

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_SOAPY=ON

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../ham/soapy-sdr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
