# $NetBSD: Makefile,v 1.43 2009/09/07 19:02:14 joerg Exp $
#

DISTNAME=	gnome-doc-utils-0.16.1
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-doc-utils/0.16/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Documentation utilities for the GNOME project

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-libxml2>=2.6.16:../../textproc/py-libxml2
DEPENDS+=	${PYPKGPREFIX}-libxslt>=1.1.12:../../textproc/py-libxslt
DEPENDS+=	docbook-xml-[0-9]*:../../textproc/docbook-xml

USE_TOOLS+=		intltool pkg-config gmake gawk msgfmt
GNU_CONFIGURE=		YES
TEST_TARGET=		check
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	PYTHON=${PYTHONBIN:Q}

PKGCONFIG_OVERRIDE=	tools/gnome-doc-utils.pc.in
PKGCONFIG_OVERRIDE+=	xml2po/xml2po.pc.in

PYTHON_PATCH_SCRIPTS=	xml2po/modes/docbook.py
PYTHON_PATCH_SCRIPTS+=	xml2po/modes/empty.py
PYTHON_PATCH_SCRIPTS+=	xml2po/modes/gs.py
PYTHON_PATCH_SCRIPTS+=	xml2po/xml2po.py

BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.6.12
BUILDLINK_DEPMETHOD.libxslt=	build
BUILDLINK_DEPMETHOD.libxml2=	build

post-install:
	${PY_COMPILE_ALL} ${DESTDIR}${PREFIX}/share/xml2po

.include "../../lang/python/application.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/xmlcatmgr/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
