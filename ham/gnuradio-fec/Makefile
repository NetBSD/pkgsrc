# $NetBSD: Makefile,v 1.92 2026/09/29 06:06:03 wiz Exp $

PKGNAME=	gnuradio-fec-${VERSION}
PKGREVISION=	16
COMMENT=	Forward Error Correction blocks, utilities, & examples of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_FEC=ON

REPLACE_PYTHON+=	gr-fec/python/fec/*.py
REPLACE_PYTHON+=	gr-fec/python/fec/LDPC/*.py
REPLACE_PYTHON+=	gr-fec/python/fec/polar/*.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
