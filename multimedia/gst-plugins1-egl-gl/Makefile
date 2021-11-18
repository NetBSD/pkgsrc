# $NetBSD: Makefile,v 1.3 2021/11/18 02:05:18 jun Exp $

CATEGORIES=		multimedia

GST_PLUGINS1_NAME=	gl
GST_PLUGINS1_FLAGS=	egl
GST_PLUGINS1_DIRS=	gst-libs/gst/gl

ONLY_FOR_PLATFORM=	NetBSD-*-*arm*

CFLAGS+=		-I${PREFIX}/include
CFLAGS+=		-I${PREFIX}/include/interface/vcos/pthreads
CFLAGS+=		-I${PREFIX}/include/interface/vmcs_host/linux
LDFLAGS+=		-Wl,-R${PREFIX}/lib -L${PREFIX}/lib

PKGREVISION= 1
.include "../../multimedia/gst-plugins1-bad/Makefile.common"

.include "../../misc/raspberrypi-userland/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
