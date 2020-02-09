# $NetBSD: Makefile,v 1.2 2020/02/09 21:54:48 jdolecek Exp $

DISTNAME=		gramps-5.1.2
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gramps/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://gramps-project.org/
COMMENT=		Genealogical Research and Analysis Management Programming System V5
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		msgfmt pkg-config intltool msgconv

PYTHON_VERSIONS_INCOMPATIBLE=	27 36

REPLACE_PYTHON+=	gramps/gen/utils/place.py
REPLACE_PYTHON+=	gramps/gen/datehandler/_date_fr.py
REPLACE_PYTHON+=	docs/update_doc.py
REPLACE_PYTHON+=	docs/conf.py
REPLACE_PYTHON+=	setup.py

# pkgsrc registers mime files using mimedb.mk (see below)
CONFIGURE_ARGS+=	--enable-packager-mode

# needs svg pixbuf loader at runtime
DEPENDS+=	librsvg-[0-9]*:../../graphics/librsvg
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

.include "options.mk"

.include "../../databases/py-bsddb3/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../mk/bsd.pkg.mk"
