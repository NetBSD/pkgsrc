# $NetBSD: Makefile,v 1.64 2024/05/29 16:33:06 adam Exp $

PKGNAME=	gnuradio-fec-${VERSION}
PKGREVISION=	3
COMMENT=	Forward Error Correction blocks, utilities, & examples of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_FEC=ON
CMAKE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
