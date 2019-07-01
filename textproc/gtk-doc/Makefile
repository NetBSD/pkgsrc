# $NetBSD: Makefile,v 1.77 2019/07/01 04:08:49 ryoon Exp $

DISTNAME=	gtk-doc-1.29
PKGREVISION=	3
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk-doc/${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gtk.org/gtk-doc/
COMMENT=	Tools for authors of the GTK+ reference documentation
LICENSE=	gnu-gpl-v3 AND gnu-fdl-v1.1

DEPENDS+=	docbook-xml>=4.4nb1:../../textproc/docbook-xml
DEPENDS+=	docbook-xsl>=1.68.1:../../textproc/docbook-xsl
DEPENDS+=	${PYPKGPREFIX}-anytree-[0-9]*:../../devel/py-anytree
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
BUILD_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	gtk-doc.pc.in
CONFIGURE_ARGS+=	--with-highlight=source-highlight
CONFIGURE_ARGS+=	--with-xml-catalog=${XML_DEFAULT_CATALOG:Q}
USE_TOOLS+=		gmake pkg-config:run msgfmt

SUBST_CLASSES+=		fix-pc
SUBST_STAGE.fix-pc=	pre-configure
SUBST_MESSAGE.fix-pc=	Unwrapping pkg-config path in installed helper tools.
SUBST_FILES.fix-pc+=	gtkdoc-depscan.in
SUBST_FILES.fix-pc+=	gtkdoc/config.py.in
SUBST_SED.fix-pc=	-e 's,@PKG_CONFIG@,pkg-config,g'

PYTHON_VERSIONS_INCOMPATIBLE=	27

# 5 tests fail in 1.29 because of missing file 'sanity.sh'
# https://gitlab.gnome.org/GNOME/gtk-doc/issues/55
TEST_TARGET=	check

.include "../../lang/python/application.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
# needed together with pkg-config by gtkdoc-depscan at runtime
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/source-highlight/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
TEST_ENV+=	LC_ALL=en_US.UTF-8
