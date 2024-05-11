# $NetBSD: Makefile,v 1.97 2024/05/11 18:58:52 adam Exp $

DISTNAME=	gtk-doc-1.34.0
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk-doc/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/gtk-doc
COMMENT=	Tools for authors of the GTK+ reference documentation
LICENSE=	gnu-gpl-v3 AND gnu-fdl-v1.1

DEPENDS+=	docbook-xml>=4.4nb1:../../textproc/docbook-xml
DEPENDS+=	docbook-xsl>=1.79.2nb6:../../textproc/docbook-xsl
DEPENDS+=	yelp-tools-[0-9]*:../../textproc/yelp-tools
DEPENDS+=	${PYPKGPREFIX}-anytree-[0-9]*:../../devel/py-anytree
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-parameterized-[0-9]*:../../devel/py-parameterized

MESON_REQD+=		0.55
USE_TOOLS+=		itstool msgfmt pkg-config:run
PKGCONFIG_OVERRIDE=	gtk-doc.pc.in

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/tests/gobject/src
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/output/tests/gobject/src
TEST_TARGET=	check

SUBST_CLASSES+=		fix-pc
SUBST_STAGE.fix-pc=	pre-configure
SUBST_MESSAGE.fix-pc=	Unwrapping pkg-config path in installed helper tools.
SUBST_FILES.fix-pc+=	gtkdoc-depscan.in
SUBST_FILES.fix-pc+=	gtkdoc/config_data.py.in
SUBST_SED.fix-pc=	-e 's,@PKG_CONFIG@,pkg-config,g'

SUBST_CLASSES+=		python3
SUBST_STAGE.python3=	pre-configure
SUBST_MESSAGE.python3=	Fix python binary name.
SUBST_FILES.python3=	meson.build
SUBST_SED.python3=	-e "s,find_installation('python3',find_installation('${PYTHONBIN}',"

PYTHON_VERSIONS_INCOMPATIBLE=	27

# needed together with pkg-config by gtkdoc-depscan at runtime
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
TEST_ENV+=	LC_ALL=en_US.UTF-8
