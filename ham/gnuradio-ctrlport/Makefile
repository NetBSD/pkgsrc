# $NetBSD: Makefile,v 1.68 2024/11/01 00:52:18 wiz Exp $

PKGNAME=	gnuradio-ctrlport-${VERSION}
PKGREVISION=	7
COMMENT=	New set of hooks into GNU Radio to allow a remote client to attach

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_CTRLPORT=ON

.include "../../mk/bsd.pkg.mk"
