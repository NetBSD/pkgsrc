# $NetBSD: Makefile,v 1.5 2025/12/25 16:32:53 ryoon Exp $

COMMENT=	A portable FPGA place and route tool for Lattice iCE40 devices

NEXTPNR_TARGET=		ice40
NEXTPNR_TARGET_ARGS=	-DICESTORM_INSTALL_PREFIX=${PREFIX}

DEPENDS+=		icestorm>=0.0.20240227:../../devel/icestorm

.include "../../devel/nextpnr/nextpnr.mk"
