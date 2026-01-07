# $NetBSD: Makefile,v 1.61 2026/01/07 08:47:30 wiz Exp $

PKGNAME=	gnuradio-network-${VERSION}
PKGREVISION=	8
COMMENT=	Network blocks for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_NETWORK=ON

REPLACE_PYTHON+=	gr-network/python/network/*.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
