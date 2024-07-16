# $NetBSD: Makefile,v 1.65 2024/07/16 10:02:02 prlw1 Exp $

PKGNAME=	gnuradio-fec-${VERSION}
PKGREVISION=	4
COMMENT=	Forward Error Correction blocks, utilities, & examples of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_FEC=ON
CMAKE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
