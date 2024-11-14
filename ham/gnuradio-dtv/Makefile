# $NetBSD: Makefile,v 1.72 2024/11/14 22:20:20 wiz Exp $

PKGNAME=	gnuradio-dtv-${VERSION}
PKGREVISION=	9
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
