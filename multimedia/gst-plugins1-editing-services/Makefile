# $NetBSD: Makefile,v 1.16 2022/01/28 12:19:30 wiz Exp $

DISTNAME=	gst-editing-services-1.18.5
PKGNAME=	${DISTNAME:S/gst-/gst-plugins1-/1}
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gst-editing-services/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gstreamer.freedesktop.org/modules/gst-editing-services.html
COMMENT=	Open source multimedia framework - editing services plugin
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

USE_TOOLS+=	flex pkg-config

PY_PATCHPLIST=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

# workaround for build failure
# https://gitlab.gnome.org/GNOME/json-glib/issues/35
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/ges

.include "../../devel/meson/build.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/tool.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
BUILDLINK_API_DEPENDS.gstreamer1+=	gstreamer1>=1.18
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.include "../../multimedia/gst-plugins1-bad/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
