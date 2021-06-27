# $NetBSD: Makefile,v 1.29 2021/06/27 08:08:59 tnn Exp $

PKGNAME=	gnuradio-ctrlport-${VERSION}
COMMENT=	New set of hooks into GNU Radio to allow a remote client to attach
.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_CTRLPORT=ON

.include	"../../mk/bsd.pkg.mk"
