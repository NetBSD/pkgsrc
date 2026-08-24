# $NetBSD: Makefile,v 1.66 2026/08/24 08:42:22 adam Exp $

PKGNAME=	gnuradio-network-${VERSION}
PKGREVISION=	13
COMMENT=	Network blocks for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_NETWORK=ON

REPLACE_PYTHON+=	gr-network/python/network/*.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
