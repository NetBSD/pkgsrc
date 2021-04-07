# $NetBSD: Makefile,v 1.24 2021/04/07 16:14:08 tnn Exp $

PKGNAME=	gnuradio-ctrlport-${VERSION}
COMMENT=	New set of hooks into GNU Radio to allow a remote client to attach
.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_CTRLPORT=ON

.include	"../../mk/bsd.pkg.mk"
