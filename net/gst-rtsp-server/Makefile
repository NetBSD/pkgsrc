# $NetBSD: Makefile,v 1.14 2024/05/18 15:57:04 wiz Exp $

.include "../../multimedia/gstreamer1/version.mk"

DISTNAME=	gst-rtsp-server-${GST_VERSION}
CATEGORIES=	net multimedia
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gst-rtsp-server/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	https://gstreamer.freedesktop.org/modules/gst-rtsp-server.html
COMMENT=	GStreamer RTSP server
LICENSE=	gnu-lgpl-v2

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		tool

USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=		output/meson-private/*.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install

MESON_ARGS+=		-Dtests=disabled

.include "../../lang/python/pyversion.mk"

SUBST_CLASSES+=		pytoolpath
SUBST_STAGE.pytoolpath=	pre-configure
SUBST_FILES.pytoolpath=	scripts/extract-release-date-from-doap-file.py
SUBST_SED.pytoolpath=	-e '1s|.*python3\{0,1\}[^ ]*|\#!${PYTHONBIN}|'

.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
