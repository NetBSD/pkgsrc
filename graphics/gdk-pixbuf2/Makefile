# $NetBSD: Makefile,v 1.42 2019/10/06 11:07:44 nia Exp $

DISTNAME=	gdk-pixbuf-${PIXBUF2_VERSION}
PKGNAME=	${DISTNAME:S/pixbuf/pixbuf2/}
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gdk-pixbuf/${MSITE_VERSION}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.gnome.org/gdk-pixbuf
COMMENT=	Library for image loading and manipulation
LICENSE=	gnu-gpl-v2

CONFLICTS+=	gtk2+<2.22

.include "../../graphics/gdk-pixbuf2/Makefile.version"

USE_TOOLS+=	gmake pkg-config xgettext
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gdk-pixbuf

MESON_ARGS+=	-D installed_tests=false
MESON_ARGS+=	-D x11=false
MESON_ARGS+=	-D man=false
PKGCONFIG_OVERRIDE_STAGE=pre-install
PKGCONFIG_OVERRIDE=    output/meson-private/gdk-pixbuf-2.0.pc

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

REPLACE_INTERPRETER+=	py3
REPLACE.py3.old=	.*/usr/bin/env python[^ ]*
REPLACE.py3.new=	${PYTHONBIN}
REPLACE_FILES.py3+=	build-aux/gen-installed-test.py
REPLACE_FILES.py3+=	build-aux/gen-thumbnailer.py
REPLACE_FILES.py3+=	build-aux/gen-resources.py

_BUILDING_GTK2= yes
.include "loaders.mk"

pre-build:
	${CHMOD} +x ${WRKSRC}/build-aux/*.py ${WRKSRC}/build-aux/*.sh

.include "../../devel/py-meson/build.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+= glib2>=2.37.2
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection:= build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
