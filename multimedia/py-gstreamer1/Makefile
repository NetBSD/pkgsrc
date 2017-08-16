# $NetBSD: Makefile,v 1.5 2017/08/16 20:21:12 wiz Exp $

DISTNAME=		gst-python-1.2.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/gst-python/gstreamer1/}
CATEGORIES=		multimedia
MASTER_SITES=		https://gstreamer.freedesktop.org/src/gst-python/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://gstreamer.freedesktop.org/
COMMENT=		Python bindings for gstreamer1
LICENSE=		gnu-lgpl-v2.1

CONFLICTS=		gst-python-[0-9]*

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}
PY_PATCHPLIST=		yes

CONFIGURE_ENV.SunOS+=	ac_cv_prog_cc_c99=no

BUILDLINK_API_DEPENDS.gstreamer1+=	gstreamer1>=1.2.0
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/py-gobject3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
