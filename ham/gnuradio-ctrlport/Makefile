# $NetBSD: Makefile,v 1.51 2023/05/16 21:20:50 wiz Exp $

PKGNAME=	gnuradio-ctrlport-${VERSION}
PKGREVISION=	4
COMMENT=	New set of hooks into GNU Radio to allow a remote client to attach

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_CTRLPORT=ON

.include "../../mk/bsd.pkg.mk"
