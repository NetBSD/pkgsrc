# $NetBSD: Makefile,v 1.27 2023/11/16 09:22:51 wiz Exp $

.include "../../multimedia/gstreamer1/version.mk"

DISTNAME=	gst-python-${GST_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/gst-python/gstreamer1/}
CATEGORIES=	multimedia
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gst-python/
EXTRACT_SUFX=	.tar.xz

COMMENT=	Python bindings for gstreamer1
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
PY_PATCHPLIST=		yes
PYTHON_SELF_CONFLICT=	yes
TEST_TARGET=		check

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/py-gobject3-common/buildlink3.mk"
BUILDLINK_API_DEPENDS.gstreamer1+=	gstreamer1>=1.20.1
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
MESON_REQD+=	1.2.0
.include "../../devel/meson/build.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
