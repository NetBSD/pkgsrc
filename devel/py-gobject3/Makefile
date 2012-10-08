# $NetBSD: Makefile,v 1.8 2012/10/08 21:15:03 prlw1 Exp $
#

DISTNAME=		pygobject-3.4.0
PKGNAME=		${PYPKGPREFIX}-gobject3-3.4.0
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

PKGCONFIG_OVERRIDE+=	pygobject-3.4.pc.in
PY_PATCHPLIST=		yes
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}
CONFLICTS+=		${PYPKGPREFIX}-gtk2<2.8.4
CONFLICTS+=		${PYPKGPREFIX}-gobject<2.28.6nb4

REPLACE_PYTHON+=	docs/xsl/fixxref.py.in

# needed for tests only
# https://bugzilla.gnome.org/show_bug.cgi?id=685094
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
TEST_TARGET=    check

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gobject-introspection=	gobject-introspection>=1.33.14
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
