# $NetBSD: Makefile,v 1.18 2020/05/06 14:04:41 adam Exp $

PKGNAME=	gnuradio-ctrlport-${VERSION}
PKGREVISION=	4
COMMENT=	New set of hooks into GNU Radio to allow a remote client to attach
.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_CTRLPORT=True

.include	"../../mk/bsd.pkg.mk"
