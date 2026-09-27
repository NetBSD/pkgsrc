# $NetBSD: Makefile,v 1.91 2026/09/27 11:37:06 tnn Exp $

PKGNAME=	gnuradio-fec-${VERSION}
PKGREVISION=	15
COMMENT=	Forward Error Correction blocks, utilities, & examples of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_FEC=ON

REPLACE_PYTHON+=	gr-fec/python/fec/*.py
REPLACE_PYTHON+=	gr-fec/python/fec/LDPC/*.py
REPLACE_PYTHON+=	gr-fec/python/fec/polar/*.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
