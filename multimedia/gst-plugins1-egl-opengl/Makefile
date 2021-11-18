# $NetBSD: Makefile,v 1.3 2021/11/18 02:06:40 jun Exp $

CATEGORIES=		multimedia

GST_PLUGINS1_NAME=	opengl
GST_PLUGINS1_FLAGS=	egl
GST_PLUGINS1_DIRS=	ext/gl

ONLY_FOR_PLATFORM=	NetBSD-*-*arm*

CFLAGS+=		-I${PREFIX}/include
CFLAGS+=		-I${PREFIX}/include/interface/vcos/pthreads
CFLAGS+=		-I${PREFIX}/include/interface/vmcs_host/linux
LDFLAGS+=		-Wl,-R${PREFIX}/lib -L${PREFIX}/lib

PKGREVISION= 1
.include "../../multimedia/gst-plugins1-bad/Makefile.common"

.include "../../multimedia/gst-plugins1-egl-gl/buildlink3.mk"
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
