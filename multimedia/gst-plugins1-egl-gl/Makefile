# $NetBSD: Makefile,v 1.5 2022/03/31 09:23:13 nia Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-egl-gl/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - AV1 plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	gl

#Looking for a fallback subproject for the dependency gstreamer-gl-1.0
BROKEN=		"Needs updating for gstreamer1 1.18.x"

#GST_PLUGINS1_NAME=	gl
#GST_PLUGINS1_FLAGS=	egl
#GST_PLUGINS1_DIRS=	gst-libs/gst/gl

ONLY_FOR_PLATFORM=	NetBSD-*-*arm*

CFLAGS+=		-I${PREFIX}/include
CFLAGS+=		-I${PREFIX}/include/interface/vcos/pthreads
CFLAGS+=		-I${PREFIX}/include/interface/vmcs_host/linux
LDFLAGS+=		-Wl,-R${PREFIX}/lib -L${PREFIX}/lib

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
