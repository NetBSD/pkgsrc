# $NetBSD: Makefile,v 1.46 2020/11/05 09:08:49 ryoon Exp $

DISTNAME=		gst-python-0.10.22
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/gst-python/gstreamer0.10/}
PKGREVISION=		7
CATEGORIES=		multimedia
MASTER_SITES=		https://gstreamer.freedesktop.org/src/gst-python/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://gstreamer.freedesktop.org/
COMMENT=		Python bindings for gstreamer0.10
LICENSE=		gnu-lgpl-v2.1

CONFLICTS=		gst-python-[0-9]*

USE_PKGLOCALEDIR=		yes
USE_LIBTOOL=			yes
USE_TOOLS+=			pkg-config gmake
GNU_CONFIGURE=			yes
CONFIGURE_ENV+=			PYTHON=${PYTHONBIN}
PY_PATCHPLIST=			yes
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.10.22; use py-gobjects

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
