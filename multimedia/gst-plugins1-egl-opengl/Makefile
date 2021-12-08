# $NetBSD: Makefile,v 1.6 2021/12/08 16:05:48 adam Exp $

PKGNAME=		${DISTNAME:S/plugins/plugins1/:S/-bad/-egl-opengl/}
PKGREVISION=		1
CATEGORIES=		multimedia gnomed

COMMENT=	Open source multimedia framework - AV1 plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	opengl

#GST_PLUGINS1_NAME=	opengl
#GST_PLUGINS1_FLAGS=	egl
#GST_PLUGINS1_DIRS=	ext/gl

BROKEN=			"Needs to be updated to gstreamer 1.18.5"

#ONLY_FOR_PLATFORM=	NetBSD-*-*arm*

CFLAGS+=		-I${PREFIX}/include
CFLAGS+=		-I${PREFIX}/include/interface/vcos/pthreads
CFLAGS+=		-I${PREFIX}/include/interface/vmcs_host/linux
LDFLAGS+=		-Wl,-R${PREFIX}/lib -L${PREFIX}/lib

.include "../../multimedia/gst-plugins1-bad/Makefile.common"

#.include "../../multimedia/gst-plugins1-egl-gl/buildlink3.mk"
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
