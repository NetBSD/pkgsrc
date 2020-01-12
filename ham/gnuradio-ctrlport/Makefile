# $NetBSD: Makefile,v 1.17 2020/01/12 20:20:24 ryoon Exp $

PKGNAME=	gnuradio-ctrlport-${VERSION}
PKGREVISION=	3
COMMENT=	New set of hooks into GNU Radio to allow a remote client to attach
.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_CTRLPORT=True

.include	"../../mk/bsd.pkg.mk"
