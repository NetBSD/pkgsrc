# $NetBSD: Makefile,v 1.1 2022/01/28 14:00:29 wiz Exp $

DISTNAME=	pygobject-3.36.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//:S/-/3-/}
PKGREVISION=	3
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pygobject/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://pygobject.readthedocs.io/
COMMENT=	Python bindings for glib2 gobject
LICENSE=	gnu-lgpl-v2.1

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c99
USE_TOOLS+=		pkg-config

CONFLICTS+=		${PYPKGPREFIX}-gtk2<2.8.4
CONFLICTS+=		${PYPKGPREFIX}-gobject<2.28.6nb4

EGG_NAME=	${DISTNAME:S/pygobject/PyGObject/}

MESON_ARGS+=	-Dpython=${PYTHONBIN:Q}
MESON_ARGS+=	-Dtests=false
TEST_TARGET=	check

PYTHON_VERSIONS_ACCEPTED=	27

# Conflicts with py-gobject3-common and not used by py27-gobject3 users
post-install:
	${RM} \
	${DESTDIR}${PREFIX}/include/pygobject-3.0/pygobject.h \
	${DESTDIR}${PREFIX}/lib/pkgconfig/pygobject-3.0.pc

BUILDLINK_API_DEPENDS.glib2=	glib2>=2.48.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gobject-introspection=	gobject-introspection>=1.46.0
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
#.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../devel/meson/build.mk"
# https://bugzilla.gnome.org/show_bug.cgi?id=685094
# https://bugzilla.gnome.org/show_bug.cgi?id=707196
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
