# $NetBSD: Makefile,v 1.21 2022/01/29 07:22:54 wiz Exp $

DISTNAME=	gst-python-1.18.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/gst-python/gstreamer1/}
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gst-python/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gstreamer.freedesktop.org/
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
BUILDLINK_API_DEPENDS.gstreamer1+=	gstreamer1>=1.18.5
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
