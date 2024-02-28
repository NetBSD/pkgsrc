# $NetBSD: Makefile,v 1.1 2024/02/28 06:31:58 thorpej Exp $

COMMENT=	A portable FPGA place and route tool for Lattice iCE40 devices

NEXTPNR_TARGET=		ice40
NEXTPNR_TARGET_ARGS=	-DICESTORM_INSTALL_PREFIX=${PREFIX}

DEPENDS+=		icestorm>=0.0.20240227:../../devel/icestorm

.include "../../devel/nextpnr/nextpnr.mk"
