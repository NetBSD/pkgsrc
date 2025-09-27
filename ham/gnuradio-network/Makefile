# $NetBSD: Makefile,v 1.59 2025/09/27 09:57:22 wiz Exp $

PKGNAME=	gnuradio-network-${VERSION}
PKGREVISION=	6
COMMENT=	Network blocks for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_NETWORK=ON

REPLACE_PYTHON+=	gr-network/python/network/*.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
