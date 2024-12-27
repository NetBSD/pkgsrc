# $NetBSD: Makefile,v 1.72 2024/12/27 08:20:05 wiz Exp $

PKGNAME=	gnuradio-ctrlport-${VERSION}
PKGREVISION=	11
COMMENT=	New set of hooks into GNU Radio to allow a remote client to attach

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_CTRLPORT=ON

.include "../../mk/bsd.pkg.mk"
