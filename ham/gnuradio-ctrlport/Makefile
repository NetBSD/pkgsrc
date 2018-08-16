# $NetBSD: Makefile,v 1.12 2018/08/16 18:54:54 adam Exp $

PKGNAME=	gnuradio-ctrlport-${VERSION}
PKGREVISION=	1
COMMENT=	New set of hooks into GNU Radio to allow a remote client to attach
.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_CTRLPORT=True

.include	"../../mk/bsd.pkg.mk"
