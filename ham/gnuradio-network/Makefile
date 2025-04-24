# $NetBSD: Makefile,v 1.55 2025/04/24 14:14:44 wiz Exp $

PKGNAME=	gnuradio-network-${VERSION}
PKGREVISION=	2
COMMENT=	Network blocks for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_NETWORK=ON

REPLACE_PYTHON+=	gr-network/python/network/*.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
