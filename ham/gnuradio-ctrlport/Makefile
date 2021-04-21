# $NetBSD: Makefile,v 1.26 2021/04/21 13:24:51 adam Exp $

PKGNAME=	gnuradio-ctrlport-${VERSION}
PKGREVISION=	2
COMMENT=	New set of hooks into GNU Radio to allow a remote client to attach
.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_CTRLPORT=ON

.include	"../../mk/bsd.pkg.mk"
