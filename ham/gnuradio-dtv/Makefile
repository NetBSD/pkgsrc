# $NetBSD: Makefile,v 1.91 2026/09/02 19:02:59 wiz Exp $

PKGNAME=	gnuradio-dtv-${VERSION}
PKGREVISION=	14
COMMENT=	Various digital television standards of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_DTV=ON

REPLACE_PYTHON+=	gr-dtv/python/dtv/*.py

.include "../../ham/gnuradio-fec/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
