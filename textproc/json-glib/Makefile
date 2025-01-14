# $NetBSD: Makefile,v 1.43 2025/01/14 21:39:41 adam Exp $

DISTNAME=	json-glib-1.10.6
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/JsonGlib
COMMENT=	JSON parser for GLib-based libraries and applications
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

USE_TOOLS+=	msgfmt pkg-config xgettext

MESON_REQD+=	1.2.0
MESON_ARGS+=	-Dman=true
MESON_ARGS+=	-Dgtk_doc=disabled
MESON_ARGS+=	-Dintrospection=enabled

SUBST_CLASSES+=		rst2man
SUBST_MESSAGE.rst2man=	Fixing rst2man binary nameversioning.
SUBST_STAGE.rst2man=	pre-configure
SUBST_FILES.rst2man=	doc/meson.build
SUBST_SED.rst2man+=	-e "s,'rst2man','rst2man-${PYVERSSUFFIX}',g"
SUBST_SED.rst2man+=	-e "s,'rst2html5','rst2html5-${PYVERSSUFFIX}',g"

#.include "../../mk/compiler.mk"

#.if !empty(PKGSRC_COMPILER:Mclang)
#_WRAP_EXTRA_ARGS.CC+=	-Wno-error=void-pointer-to-int-cast
#CWRAPPERS_APPEND.cc+=	-Wno-error=void-pointer-to-int-cast
#.endif

# workaround for build failure
# https://gitlab.gnome.org/GNOME/json-glib/issues/35
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/json-glib

PRINT_PLIST_AWK+= \
	($$0 ~ /^lib\/girepository-1.0\//) || \
	($$0 ~ /^share\/gir-1.0\//) \
	{ $$0 = "$${PLIST.introspection}" $$0; }

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.72.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
