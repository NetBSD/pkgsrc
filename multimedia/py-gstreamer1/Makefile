# $NetBSD: Makefile,v 1.3 2015/04/13 23:12:42 rodent Exp $

DISTNAME=		gst-python-1.2.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/gst-python/gstreamer1/}
CATEGORIES=		multimedia
MASTER_SITES=		http://gstreamer.freedesktop.org/src/gst-python/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gstreamer.freedesktop.org/
COMMENT=		Python bindings for gstreamer1
LICENSE=		gnu-lgpl-v2.1

CONFLICTS=		gst-python-[0-9]*

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}
PY_PATCHPLIST=		yes

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=		ac_cv_prog_cc_c99=no
.endif

BUILDLINK_API_DEPENDS.gstreamer1+=	gstreamer1>=1.2.0
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/py-gobject3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
