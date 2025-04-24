# $NetBSD: Makefile,v 1.76 2025/04/24 14:14:44 wiz Exp $

PKGNAME=	gnuradio-channels-${VERSION}
PKGREVISION=	2
COMMENT=	Signal processing blocks to simulate channel models of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_CHANNELS=ON

REPLACE_PYTHON+=	gr-channels/python/channels/*.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
