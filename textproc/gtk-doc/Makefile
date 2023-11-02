# $NetBSD: Makefile,v 1.95 2023/11/02 10:47:22 wiz Exp $

DISTNAME=	gtk-doc-1.32
PKGREVISION=	14
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk-doc/${PKGVERSION_NOREV}/}
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

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	gtk-doc.pc.in
CONFIGURE_ARGS+=	--with-xml-catalog=${XML_DEFAULT_CATALOG:Q}
USE_TOOLS+=		gmake pkg-config:run msgfmt
USE_TOOLS+=		itstool

SUBST_CLASSES+=		fix-pc
SUBST_STAGE.fix-pc=	pre-configure
SUBST_MESSAGE.fix-pc=	Unwrapping pkg-config path in installed helper tools.
SUBST_FILES.fix-pc+=	gtkdoc-depscan.in
SUBST_FILES.fix-pc+=	gtkdoc/config.py.in
SUBST_SED.fix-pc=	-e 's,@PKG_CONFIG@,pkg-config,g'

PYTHON_VERSIONS_INCOMPATIBLE=	27

TEST_TARGET=	check

.include "../../lang/python/application.mk"
# needed together with pkg-config by gtkdoc-depscan at runtime
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
TEST_ENV+=	LC_ALL=en_US.UTF-8
