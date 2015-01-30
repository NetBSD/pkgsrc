# $NetBSD: Makefile,v 1.1 2015/01/30 11:09:45 jmcneill Exp $

GST_PLUGINS1_NAME=	gl
GST_PLUGINS1_FLAGS=	egl
GST_PLUGINS1_DIRS=	gst-libs/gst/gl

ONLY_FOR_PLATFORM=	NetBSD-*-*arm*

CFLAGS+=		-I${PREFIX}/include
CFLAGS+=		-I${PREFIX}/include/interface/vcos/pthreads
CFLAGS+=		-I${PREFIX}/include/interface/vmcs_host/linux
LDFLAGS+=		-Wl,-R${PREFIX}/lib -L${PREFIX}/lib

.include "../../multimedia/gst-plugins1-bad/Makefile.common"

.include "../../misc/raspberrypi-userland/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
