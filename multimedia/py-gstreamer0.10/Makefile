# $NetBSD: Makefile,v 1.35 2016/02/25 15:49:44 jperkin Exp $

DISTNAME=		gst-python-0.10.22
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/gst-python/gstreamer0.10/}
PKGREVISION=		4
CATEGORIES=		multimedia
MASTER_SITES=		http://gstreamer.freedesktop.org/src/gst-python/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gstreamer.freedesktop.org/
COMMENT=		Python bindings for gstreamer0.10
LICENSE=		gnu-lgpl-v2.1

CONFLICTS=		gst-python-[0-9]*

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}
PY_PATCHPLIST=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.10.22; use py-gobjects

PKGCONFIG_OVERRIDE+=	pkgconfig/gst-python.pc.in

CONFIGURE_ENV.SunOS+=	ac_cv_prog_cc_c99=no

.include "../../multimedia/gstreamer0.10/buildlink3.mk"
BUILDLINK_API_DEPENDS.gst-plugins0.10-base+=	gst-plugins0.10-base>=0.10.26
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.pygobject+=	 ${PYPKGPREFIX}-gobject>=2.15.0
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
