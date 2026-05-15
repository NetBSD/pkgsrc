# $NetBSD: Makefile,v 1.63 2026/05/15 09:58:53 adam Exp $

PKGNAME=	gnuradio-network-${VERSION}
PKGREVISION=	10
COMMENT=	Network blocks for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_NETWORK=ON

REPLACE_PYTHON+=	gr-network/python/network/*.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
