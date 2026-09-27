# $NetBSD: Makefile,v 1.68 2026/09/27 11:37:06 tnn Exp $

PKGNAME=	gnuradio-network-${VERSION}
PKGREVISION=	15
COMMENT=	Network blocks for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_NETWORK=ON

REPLACE_PYTHON+=	gr-network/python/network/*.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
