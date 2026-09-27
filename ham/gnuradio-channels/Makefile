# $NetBSD: Makefile,v 1.89 2026/09/27 11:37:05 tnn Exp $

PKGNAME=	gnuradio-channels-${VERSION}
PKGREVISION=	15
COMMENT=	Signal processing blocks to simulate channel models of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_CHANNELS=ON

REPLACE_PYTHON+=	gr-channels/python/channels/*.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
