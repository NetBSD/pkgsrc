# $NetBSD: Makefile,v 1.88 2026/08/24 08:42:22 adam Exp $

PKGNAME=	gnuradio-digital-${VERSION}
PKGREVISION=	13
COMMENT=	Digital related algorithms for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_DIGITAL=ON

REPLACE_PYTHON+=	gr-digital/examples/narrowband/*.py
REPLACE_PYTHON+=	gr-digital/python/digital/*.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
