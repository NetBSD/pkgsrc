# $NetBSD: Makefile,v 1.34 2022/01/10 01:46:35 ryoon Exp $

PKGNAME=	gnuradio-ctrlport-${VERSION}
PKGREVISION=	1
COMMENT=	New set of hooks into GNU Radio to allow a remote client to attach
.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_CTRLPORT=ON

.include	"../../mk/bsd.pkg.mk"
