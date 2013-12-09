# $NetBSD: Makefile,v 1.22 2013/12/09 23:12:31 prlw1 Exp $

DISTNAME=		pygobject-3.10.2
PKGNAME=		${PYPKGPREFIX}-gobject3-3.10.2
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/pygobject/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		prlw1@cam.ac.uk
HOMEPAGE=		http://www.pygtk.org/
COMMENT=		Python bindings for glib2 gobject
LICENSE=		gnu-lgpl-v2.1

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c99
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

#PYTHON_VERSIONS_INCLUDE_3X=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	26
PYTHON_SELF_CONFLICT=		yes

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
.if exists(${PYTHONBIN:Q})
PLATFORM!=	${PYTHONBIN:Q} -c "import sys; from distutils import util; sys.stdout.write(util.get_platform())"
PLIST_SUBST+=	PLATFORM=${PLATFORM:Q}
.endif

BUILDLINK_API_DEPENDS.glib2=	glib2>=2.35.9
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gobject-introspection=	gobject-introspection>=1.35.9
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
