# $NetBSD: Makefile,v 1.75 2025/02/12 06:45:13 ryoon Exp $

PKGNAME=	gnuradio-fec-${VERSION}
PKGREVISION=	13
COMMENT=	Forward Error Correction blocks, utilities, & examples of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_FEC=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
