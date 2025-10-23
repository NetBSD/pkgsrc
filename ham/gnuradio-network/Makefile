# $NetBSD: Makefile,v 1.60 2025/10/23 20:37:52 wiz Exp $

PKGNAME=	gnuradio-network-${VERSION}
PKGREVISION=	7
COMMENT=	Network blocks for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_NETWORK=ON

REPLACE_PYTHON+=	gr-network/python/network/*.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
