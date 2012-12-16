# $NetBSD: Makefile,v 1.12 2012/12/16 21:44:40 wiz Exp $
#

DISTNAME=		pygobject-3.4.2
PKGNAME=		${PYPKGPREFIX}-gobject3-3.4.2
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/pygobject/3.4/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		prlw1@cam.ac.uk
HOMEPAGE=		http://www.pygtk.org/
COMMENT=		Python bindings for glib2 gobject
LICENSE=		gnu-lgpl-v2.1

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

PKGCONFIG_OVERRIDE+=	pygobject-3.0.pc.in
PY_PATCHPLIST=		yes
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}
CONFLICTS+=		${PYPKGPREFIX}-gtk2<2.8.4
CONFLICTS+=		${PYPKGPREFIX}-gobject<2.28.6nb4

# needed for tests only
# https://bugzilla.gnome.org/show_bug.cgi?id=685094
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
TEST_TARGET=    check

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"

# for the egg
PLATFORM!=	${PYTHONBIN:Q} -c "import sys; from distutils import util; sys.stdout.write(util.get_platform())"
PLIST_SUBST+=	PLATFORM=${PLATFORM:Q}

.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gobject-introspection=	gobject-introspection>=1.34.1.1
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
