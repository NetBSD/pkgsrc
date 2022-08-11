# $NetBSD: Makefile,v 1.53 2022/08/11 05:08:12 gutteridge Exp $

DISTNAME=	libpeas-1.26.0
PKGREVISION=	4
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libpeas/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Libpeas
COMMENT=	GObject-based plugins engine
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

USE_TOOLS+=	msgfmt pkg-config

MESON_ARGS+=	-Dpython3=true
# XXX: revisit at later date if something needs this
MESON_ARGS+=	-Dpython2=false
MESON_ARGS+=	-Dlua51=false

PYTHON_VERSIONS_INCOMPATIBLE=	27 37
PYTHON_FOR_BUILD_ONLY=		yes

PKGCONFIG_OVERRIDE+=	output/meson-private/libpeas-gtk-1.0.pc
PKGCONFIG_OVERRIDE+=	output/meson-private/libpeas-1.0.pc

PKGCONFIG_OVERRIDE_STAGE=	post-configure

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/libpeas:${WRKSRC}/output/libpeas-gtk:${WRKSRC}/output/tests/libpeas/introspection

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python+=	meson.build
SUBST_SED.python+=	-e "s/python3-embed/python-${PYVERSSUFFIX}-embed/"
SUBST_MESSAGE.python=	Fix path for python configure tool.

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.38.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=1.39.0
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
