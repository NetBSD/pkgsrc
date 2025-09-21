# $NetBSD: Makefile,v 1.58 2025/09/21 18:15:06 wiz Exp $

PKGNAME=	gnuradio-network-${VERSION}
PKGREVISION=	5
COMMENT=	Network blocks for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_NETWORK=ON

REPLACE_PYTHON+=	gr-network/python/network/*.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
