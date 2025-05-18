# $NetBSD: Makefile,v 1.80 2025/05/18 19:31:20 gdt Exp $

PKGNAME=	gnuradio-dtv-${VERSION}
PKGREVISION=	3
COMMENT=	Various digital television standards of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_DTV=ON

REPLACE_PYTHON+=	gr-dtv/python/dtv/*.py

.include "../../ham/gnuradio-fec/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
