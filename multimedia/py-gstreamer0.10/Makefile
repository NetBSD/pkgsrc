# $NetBSD: Makefile,v 1.3 2007/01/05 11:04:42 drochner Exp $
#

DISTNAME=		gst-python-0.10.6
CATEGORIES=		multimedia
MASTER_SITES=		http://gstreamer.freedesktop.org/src/gst-python/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gstreamer.freedesktop.org/
COMMENT=		Python bindings for gstreamer0.10

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}
PYTHON_VERSIONS_ACCEPTED= 23 24
PY_PATCHPLIST=		yes

PKGCONFIG_OVERRIDE+=	pkgconfig/gst-python.pc.in

.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
