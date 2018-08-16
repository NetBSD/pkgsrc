# $NetBSD: Makefile,v 1.72 2018/08/16 18:55:13 adam Exp $

DISTNAME=	gtk-doc-1.28
PKGREVISION=	2
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk-doc/${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gtk.org/gtk-doc/
COMMENT=	Tools for authors of the GTK+ reference documentation
LICENSE=	gnu-gpl-v3 AND gnu-fdl-v1.1

DEPENDS+=	docbook-xml>=4.4nb1:../../textproc/docbook-xml
DEPENDS+=	docbook-xsl>=1.68.1:../../textproc/docbook-xsl
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
BUILD_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	gtk-doc.pc.in
CONFIGURE_ARGS+=	--with-highlight=source-highlight
CONFIGURE_ARGS+=	--with-xml-catalog=${XML_DEFAULT_CATALOG:Q}
USE_TOOLS+=		gmake pkg-config:run msgfmt

# one test failure that's not there with python-2.x as of 1.26
# https://bugzilla.gnome.org/show_bug.cgi?id=786174
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37

SUBST_CLASSES+=		fix-pc
SUBST_STAGE.fix-pc=	pre-configure
SUBST_MESSAGE.fix-pc=	Unwrapping pkg-config path in installed helper tools.
SUBST_FILES.fix-pc+=	gtkdoc-depscan.in
SUBST_FILES.fix-pc+=	gtkdoc/config.py.in
SUBST_SED.fix-pc=	-e 's,@PKG_CONFIG@,pkg-config,g'

MAKE_JOBS_SAFE=		no

TEST_TARGET=	check

REPLACE_PYTHON=		tests/check.py
REPLACE_PYTHON+=	tests/common.py
REPLACE_PYTHON+=	tests/mk_to_db.py

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
