# $NetBSD: Makefile,v 1.19 2020/05/23 00:04:18 mef Exp $

PKGNAME=	gnuradio-ctrlport-${VERSION}
PKGREVISION=	4
COMMENT=	New set of hooks into GNU Radio to allow a remote client to attach
.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_CTRLPORT=True

REPLACE_PYTHON=		gnuradio-runtime/python/gnuradio/ctrlport/gr-perf-monitorx
REPLACE_PYTHON+=	gnuradio-runtime/python/gnuradio/ctrlport/gr-ctrlport-monitor

.include	"../../mk/bsd.pkg.mk"
