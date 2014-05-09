# $NetBSD: Makefile,v 1.42 2014/05/09 07:36:56 wiz Exp $

DISTNAME=		gourmet-0.8.5.14
PKGREVISION=		30
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=grecipe-manager/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://grecipe-manager.sourceforge.net/
COMMENT=		Recipe database

USE_PKGLOCALEDIR=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-metakit, py-imaging, py-gtk2

REPLACE_PYTHON+=	build_rpms.py
REPLACE_PYTHON+=	setup.py
REPLACE_PYTHON+=	src/gourmet
REPLACE_PYTHON+=	src/lib/FauxActionGroups.py
REPLACE_PYTHON+=	src/lib/GourmetRecipeManager.py
REPLACE_PYTHON+=	src/lib/ThumbnailGenerator.py
REPLACE_PYTHON+=	src/lib/WidgetSaver.py
REPLACE_PYTHON+=	src/lib/convert.py
REPLACE_PYTHON+=	src/lib/defaults_en.py
REPLACE_PYTHON+=	src/lib/defaults_es.py
REPLACE_PYTHON+=	src/lib/defaults_fr.py
REPLACE_PYTHON+=	src/lib/defaults_nl.py
REPLACE_PYTHON+=	src/lib/defaults_pt.py
REPLACE_PYTHON+=	src/lib/defaults_sk.py
REPLACE_PYTHON+=	src/lib/dialog_extras.py
REPLACE_PYTHON+=	src/lib/exporters/recipe_emailer.py
REPLACE_PYTHON+=	src/lib/gdebug.py
REPLACE_PYTHON+=	src/lib/importers/importer.py
REPLACE_PYTHON+=	src/lib/importers/mastercook_importer.py
REPLACE_PYTHON+=	src/lib/importers/mealmaster_importer.py
REPLACE_PYTHON+=	src/lib/optionTable.py
REPLACE_PYTHON+=	src/lib/prefs.py
REPLACE_PYTHON+=	src/lib/reccard.py
REPLACE_PYTHON+=	src/lib/recindex.py
REPLACE_PYTHON+=	src/lib/shopgui.py
REPLACE_PYTHON+=	src/lib/shopgui.py.orig
REPLACE_PYTHON+=	src/lib/timeEntry.py
REPLACE_PYTHON+=	src/lib/treeview_extras.py
REPLACE_PYTHON+=	src/lib/version.py
REPLACE_PYTHON+=	windows/Gourmet.pyw

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../databases/py-metakit/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
