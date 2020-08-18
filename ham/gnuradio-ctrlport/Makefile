# $NetBSD: Makefile,v 1.20 2020/08/18 17:58:03 leot Exp $

PKGNAME=	gnuradio-ctrlport-${VERSION}
PKGREVISION=	5
COMMENT=	New set of hooks into GNU Radio to allow a remote client to attach
.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_CTRLPORT=True

REPLACE_PYTHON=		gnuradio-runtime/python/gnuradio/ctrlport/gr-perf-monitorx
REPLACE_PYTHON+=	gnuradio-runtime/python/gnuradio/ctrlport/gr-ctrlport-monitor

.include	"../../mk/bsd.pkg.mk"
