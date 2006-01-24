# $NetBSD: Makefile,v 1.11 2006/01/24 07:32:36 wiz Exp $
#

DISTNAME=	gnome-doc-utils-0.4.4
PKGREVISION=	1
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-doc-utils/0.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Documentation utilities for the GNOME project

DEPENDS+=	${PYPKGPREFIX}-libxml2>=2.6.16:../../textproc/py-libxml2
DEPENDS+=	${PYPKGPREFIX}-libxslt>=1.1.12:../../textproc/py-libxslt

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_LANGUAGES=		# empty
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	PYTHON=${PYTHONBIN:Q}

PKGCONFIG_OVERRIDE=	gnome-doc-utils.pc.in
PKGCONFIG_OVERRIDE+=	xml2po/xml2po.pc.in

PYTHON_PATCH_SCRIPTS=	xml2po/modes/docbook.py
PYTHON_PATCH_SCRIPTS+=	xml2po/modes/empty.py
PYTHON_PATCH_SCRIPTS+=	xml2po/modes/gs.py
PYTHON_PATCH_SCRIPTS+=	xml2po/xml2po.py

BUILDLINK_DEPMETHOD.libxslt?=	build
BUILDLINK_DEPMETHOD.libxml2?=	build

.include "../../lang/python/application.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/xmlcatmgr/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
