# $NetBSD: Makefile,v 1.56 2025/05/18 19:31:20 gdt Exp $

PKGNAME=	gnuradio-network-${VERSION}
PKGREVISION=	3
COMMENT=	Network blocks for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_NETWORK=ON

REPLACE_PYTHON+=	gr-network/python/network/*.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
