# $NetBSD: Makefile,v 1.16 2019/11/26 13:07:46 wiz Exp $

DISTNAME=	gst-python-1.16.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/gst-python/gstreamer1/}
CATEGORIES=	multimedia
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gst-python/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gstreamer.freedesktop.org/
COMMENT=	Python bindings for gstreamer1
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}
CONFIGURE_ENV.SunOS+=	ac_cv_prog_cc_c99=no
PY_PATCHPLIST=		yes
TEST_TARGET=		check

.include "../../devel/py-gobject3-common/buildlink3.mk"
BUILDLINK_API_DEPENDS.gstreamer1+=	gstreamer1>=1.16.0
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
