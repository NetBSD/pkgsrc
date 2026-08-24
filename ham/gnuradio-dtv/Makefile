# $NetBSD: Makefile,v 1.90 2026/08/24 08:42:22 adam Exp $

PKGNAME=	gnuradio-dtv-${VERSION}
PKGREVISION=	13
COMMENT=	Various digital television standards of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_DTV=ON

REPLACE_PYTHON+=	gr-dtv/python/dtv/*.py

.include "../../ham/gnuradio-fec/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
