# $NetBSD: Makefile,v 1.4 2026/05/15 09:58:47 adam Exp $

COMMENT=	Portable FPGA place and route tool

PKGREVISION=	2

NEXTPNR_TARGET=		himbaechel
NEXTPNR_TARGET_ARGS=	-DICESTORM_INSTALL_PREFIX=${PREFIX}
# xilinx, ng-ultra and gatemate require more dependencies.
NEXTPNR_TARGET_ARGS+=	-DHIMBAECHEL_UARCH="gowin" # separate with ;

DEPENDS+=		${PYPKGPREFIX}-apycula-[0-9]*:../../devel/py-apycula

MAINTAINER=	ryoon@NetBSD.org

.include "../../devel/nextpnr/nextpnr.mk"
