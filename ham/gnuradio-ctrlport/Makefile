# $NetBSD: Makefile,v 1.66 2024/10/04 03:49:27 ryoon Exp $

PKGNAME=	gnuradio-ctrlport-${VERSION}
PKGREVISION=	5
COMMENT=	New set of hooks into GNU Radio to allow a remote client to attach

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_CTRLPORT=ON

.include "../../mk/bsd.pkg.mk"
