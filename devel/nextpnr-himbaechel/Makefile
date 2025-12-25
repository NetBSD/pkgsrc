# $NetBSD: Makefile,v 1.1 2025/12/25 16:34:49 ryoon Exp $

COMMENT=	Portable FPGA place and route tool

NEXTPNR_TARGET=		himbaechel
NEXTPNR_TARGET_ARGS=	-DICESTORM_INSTALL_PREFIX=${PREFIX}
# xilinx, ng-ultra and gatemate require more dependencies.
NEXTPNR_TARGET_ARGS+=	-DHIMBAECHEL_UARCH="gowin" # separate with ;

DEPENDS+=		${PYPKGPREFIX}-apycula-[0-9]*:../../devel/py-apycula

.include "../../devel/nextpnr/nextpnr.mk"
