# $NetBSD: Makefile,v 1.85 2026/06/11 07:17:11 wiz Exp $

PKGNAME=	gnuradio-channels-${VERSION}
PKGREVISION=	11
COMMENT=	Signal processing blocks to simulate channel models of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_CHANNELS=ON

REPLACE_PYTHON+=	gr-channels/python/channels/*.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
