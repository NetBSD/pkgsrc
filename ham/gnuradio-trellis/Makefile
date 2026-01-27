# $NetBSD: Makefile,v 1.102 2026/01/27 08:39:52 wiz Exp $

PKGNAME=	gnuradio-trellis-${VERSION}
PKGREVISION=	9
COMMENT=	Trellis-based encoding and decoding algorithms for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_TRELLIS=ON

DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

REPLACE_PYTHON+=	gr-trellis/docs/*.py
REPLACE_PYTHON+=	gr-trellis/examples/python/*.py
REPLACE_PYTHON+=	gr-trellis/python/trellis/*.py

.include "../../ham/gnuradio-digital/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
