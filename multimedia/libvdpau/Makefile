# $NetBSD: Makefile,v 1.15 2019/11/27 13:36:50 nia Exp $

DISTNAME=	libvdpau-1.3
CATEGORIES=	multimedia
MASTER_SITES=	https://gitlab.freedesktop.org/vdpau/libvdpau/-/archive/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://http.download.nvidia.com/XFree86/vdpau/doxygen/html/index.html
COMMENT=	Video Decode and Presentation API for Unix
LICENSE=	mit

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

#PKGCONFIG_OVERRIDE+=	vdpau.pc.in

EGDIR=		${PREFIX}/share/examples/libvdpau
CONF_FILES=	${EGDIR}/vdpau_wrapper.cfg \
		${PKG_SYSCONFDIR}/vdpau_wrapper.cfg

MESON_ARGS+=	-Degdir=${EGDIR}

.include "available.mk"

.if ${VDPAU_AVAILABLE} == no
PKG_SKIP_REASON+=	"VDPAU is not available on this platform"
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
