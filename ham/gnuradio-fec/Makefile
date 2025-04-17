# $NetBSD: Makefile,v 1.77 2025/04/17 21:51:13 wiz Exp $

PKGNAME=	gnuradio-fec-${VERSION}
PKGREVISION=	1
COMMENT=	Forward Error Correction blocks, utilities, & examples of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_FEC=ON

REPLACE_PYTHON+=	gr-fec/python/fec/*.py
REPLACE_PYTHON+=	gr-fec/python/fec/LDPC/*.py
REPLACE_PYTHON+=	gr-fec/python/fec/polar/*.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
