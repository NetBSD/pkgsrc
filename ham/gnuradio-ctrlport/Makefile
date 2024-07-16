# $NetBSD: Makefile,v 1.64 2024/07/16 10:02:02 prlw1 Exp $

PKGNAME=	gnuradio-ctrlport-${VERSION}
PKGREVISION=	4
COMMENT=	New set of hooks into GNU Radio to allow a remote client to attach

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_CTRLPORT=ON

.include "../../mk/bsd.pkg.mk"
