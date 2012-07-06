# $NetBSD: Makefile,v 1.2 2012/07/06 04:36:07 dholland Exp $
#

DISTNAME=		pygobject-3.2.2
PKGNAME=		${PYPKGPREFIX}-gobject3-3.2.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/pygobject/3.2/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		prlw1@cam.ac.uk
HOMEPAGE=		http://www.pygtk.org/
COMMENT=		Python bindings for glib2 gobject
LICENSE=		gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

PYTHON_VERSIONS_INCOMPATIBLE=	25

PKGCONFIG_OVERRIDE+=	pygobject-3.2.pc.in
PY_PATCHPLIST=		yes
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}
CONFLICTS+=		${PYPKGPREFIX}-gtk2<2.8.4
CONFLICTS+=		${PYPKGPREFIX}-gobject<2.28.6nb4

REPLACE_PYTHON+=	docs/xsl/fixxref.py.in

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gobject-introspection=	gobject-introspection>=1.31.20
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
