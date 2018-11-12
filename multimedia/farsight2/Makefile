# $NetBSD: Makefile,v 1.73 2018/11/12 03:52:36 ryoon Exp $

DISTNAME=	farsight2-0.0.31
PKGREVISION=	33
CATEGORIES=	chat multimedia
MASTER_SITES=	http://farsight.freedesktop.org/releases/farsight2/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://farsight.freedesktop.org/wiki/
COMMENT=	Audio/video communications framework
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	farsight2.pc.in

# optionally for gstreamer unit tests
# gstreamer-check-0.10 >= 0.10.23 (GStreamer Check unittest Library)

PY_PATCHPLIST=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2, py-gstreamer0.10

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pygobject+=	${PYPKGPREFIX}-gobject>=2.16
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gst-plugins0.10-base+=	gst-plugins0.10-base>=0.10.23
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
BUILDLINK_API_DEPENDS.gstreamer0.10+=	gstreamer0.10>=0.10.23
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
BUILDLINK_API_DEPENDS.gst-python+=	${PYPKGPREFIX}-gstreamer0.10>=0.10.10
.include "../../multimedia/py-gstreamer0.10/buildlink3.mk"
.include "../../net/gupnp-igd/buildlink3.mk"
BUILDLINK_API_DEPENDS.libnice+=	libnice>=0.1.0
.include "../../net/libnice/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
