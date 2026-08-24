# $NetBSD: Makefile,v 1.5 2026/08/24 08:42:16 adam Exp $

COMMENT=	Portable FPGA place and route tool

PKGREVISION=	3

NEXTPNR_TARGET=		himbaechel
NEXTPNR_TARGET_ARGS=	-DICESTORM_INSTALL_PREFIX=${PREFIX}
# xilinx, ng-ultra and gatemate require more dependencies.
NEXTPNR_TARGET_ARGS+=	-DHIMBAECHEL_UARCH="gowin" # separate with ;

DEPENDS+=		${PYPKGPREFIX}-apycula-[0-9]*:../../devel/py-apycula

MAINTAINER=	ryoon@NetBSD.org

.include "../../devel/nextpnr/nextpnr.mk"
