# $NetBSD: Makefile,v 1.101 2026/01/07 08:47:30 wiz Exp $

PKGNAME=	gnuradio-trellis-${VERSION}
PKGREVISION=	8
COMMENT=	Trellis-based encoding and decoding algorithms for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_TRELLIS=ON

DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

REPLACE_PYTHON+=	gr-trellis/docs/*.py
REPLACE_PYTHON+=	gr-trellis/examples/python/*.py
REPLACE_PYTHON+=	gr-trellis/python/trellis/*.py

.include "../../ham/gnuradio-digital/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
