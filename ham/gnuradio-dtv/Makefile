# $NetBSD: Makefile,v 1.75 2024/12/29 15:09:52 adam Exp $

PKGNAME=	gnuradio-dtv-${VERSION}
PKGREVISION=	12
COMMENT=	Various digital television standards of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_DTV=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_FEC=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	fec companion

.include "../../ham/gnuradio-fec/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
