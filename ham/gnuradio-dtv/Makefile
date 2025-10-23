# $NetBSD: Makefile,v 1.84 2025/10/23 20:37:52 wiz Exp $

PKGNAME=	gnuradio-dtv-${VERSION}
PKGREVISION=	7
COMMENT=	Various digital television standards of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_DTV=ON

REPLACE_PYTHON+=	gr-dtv/python/dtv/*.py

.include "../../ham/gnuradio-fec/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
