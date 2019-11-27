# $NetBSD: Makefile,v 1.17 2019/11/27 13:46:53 nia Exp $

DISTNAME=	libvdpau-1.3
CATEGORIES=	multimedia
MASTER_SITES=	https://gitlab.freedesktop.org/vdpau/libvdpau/-/archive/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/wiki/Software/VDPAU/
COMMENT=	Video Decode and Presentation API for Unix
LICENSE=	mit

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

EGDIR=		${PREFIX}/share/examples/libvdpau
CONF_FILES=	${EGDIR}/vdpau_wrapper.cfg \
		${PKG_SYSCONFDIR}/vdpau_wrapper.cfg

MESON_ARGS+=	-Degdir=${EGDIR}

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/vdpau.pc

.include "available.mk"

.if ${VDPAU_AVAILABLE} == no
PKG_SKIP_REASON+=	"VDPAU is not available on this platform"
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
