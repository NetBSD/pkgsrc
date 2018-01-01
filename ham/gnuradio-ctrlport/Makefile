# $NetBSD: Makefile,v 1.9 2018/01/01 21:18:35 adam Exp $

PKGNAME=	gnuradio-ctrlport-${VERSION}
PKGREVISION=	3
COMMENT=	New set of hooks into GNU Radio to allow a remote client to attach
.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_CTRLPORT=True

.include	"../../mk/bsd.pkg.mk"
