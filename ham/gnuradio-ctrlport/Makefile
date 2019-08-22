# $NetBSD: Makefile,v 1.16 2019/08/22 12:23:22 ryoon Exp $

PKGNAME=	gnuradio-ctrlport-${VERSION}
PKGREVISION=	2
COMMENT=	New set of hooks into GNU Radio to allow a remote client to attach
.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_CTRLPORT=True

.include	"../../mk/bsd.pkg.mk"
