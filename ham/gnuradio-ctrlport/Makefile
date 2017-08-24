# $NetBSD: Makefile,v 1.8 2017/08/24 20:03:24 adam Exp $

PKGNAME=	gnuradio-ctrlport-${VERSION}
PKGREVISION=	2
COMMENT=	New set of hooks into GNU Radio to allow a remote client to attach
.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_CTRLPORT=True

.include	"../../mk/bsd.pkg.mk"
