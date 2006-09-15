# $NetBSD: Makefile,v 1.22 2006/09/15 15:05:52 jmmv Exp $
#

DISTNAME=	gnome-doc-utils-0.8.0
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-doc-utils/0.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Documentation utilities for the GNOME project

DEPENDS+=	${PYPKGPREFIX}-libxml2>=2.6.16:../../textproc/py-libxml2
DEPENDS+=	${PYPKGPREFIX}-libxslt>=1.1.12:../../textproc/py-libxslt

USE_TOOLS+=		intltool pkg-config
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	PYTHON=${PYTHONBIN:Q}

PKGCONFIG_OVERRIDE=	gnome-doc-utils.pc.in
PKGCONFIG_OVERRIDE+=	xml2po/xml2po.pc.in

PYTHON_VERSIONS_ACCEPTED=	24 23
PYTHON_PATCH_SCRIPTS=	xml2po/modes/docbook.py
PYTHON_PATCH_SCRIPTS+=	xml2po/modes/empty.py
PYTHON_PATCH_SCRIPTS+=	xml2po/modes/gs.py
PYTHON_PATCH_SCRIPTS+=	xml2po/xml2po.py

BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.6.12
BUILDLINK_DEPMETHOD.libxslt=	build
BUILDLINK_DEPMETHOD.libxml2=	build

PYCOMPILEALL=	${BUILDLINK_PREFIX.${PYPACKAGE}}/${PYLIB}/compileall.py

post-install:
	${PYTHONBIN} ${PYCOMPILEALL} ${PREFIX}/share/xml2po

.include "../../lang/python/application.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/xmlcatmgr/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
