# $NetBSD: Makefile,v 1.3 2026/03/08 12:45:35 ryoon Exp $

COMMENT=	Portable FPGA place and route tool

PKGREVISION=	1

NEXTPNR_TARGET=		himbaechel
NEXTPNR_TARGET_ARGS=	-DICESTORM_INSTALL_PREFIX=${PREFIX}
# xilinx, ng-ultra and gatemate require more dependencies.
NEXTPNR_TARGET_ARGS+=	-DHIMBAECHEL_UARCH="gowin" # separate with ;

DEPENDS+=		${PYPKGPREFIX}-apycula-[0-9]*:../../devel/py-apycula

MAINTAINER=	ryoon@NetBSD.org

.include "../../devel/nextpnr/nextpnr.mk"
