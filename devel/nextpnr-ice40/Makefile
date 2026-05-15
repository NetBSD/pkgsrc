# $NetBSD: Makefile,v 1.6 2026/05/15 09:58:47 adam Exp $

COMMENT=	A portable FPGA place and route tool for Lattice iCE40 devices
PKGREVISION=	1

NEXTPNR_TARGET=		ice40
NEXTPNR_TARGET_ARGS=	-DICESTORM_INSTALL_PREFIX=${PREFIX}

DEPENDS+=		icestorm>=0.0.20240227:../../devel/icestorm

.include "../../devel/nextpnr/nextpnr.mk"
