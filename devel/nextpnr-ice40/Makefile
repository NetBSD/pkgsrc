# $NetBSD: Makefile,v 1.2 2024/10/04 03:49:20 ryoon Exp $

COMMENT=	A portable FPGA place and route tool for Lattice iCE40 devices
PKGREVISION=	1

NEXTPNR_TARGET=		ice40
NEXTPNR_TARGET_ARGS=	-DICESTORM_INSTALL_PREFIX=${PREFIX}

DEPENDS+=		icestorm>=0.0.20240227:../../devel/icestorm

.include "../../devel/nextpnr/nextpnr.mk"
