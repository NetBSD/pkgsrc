# $NetBSD: Makefile,v 1.26 2011/11/20 20:04:14 gls Exp $
#

DISTNAME=	calibre-0.8.27
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=calibre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.calibre-ebook.com/
COMMENT=	E-book library management application
LICENSE=	gnu-gpl-v3

DEPENDS+=	help2man>=1.36.4:../../converters/help2man
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	xdg-utils>=1.0.2:../../misc/xdg-utils
DEPENDS+=	poppler-utils-[0-9]*:../../print/poppler-utils
DEPENDS+=	${PYPKGPREFIX}-dns>=1.6.0:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.2.1:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.4.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-ClientForm-[0-9]*:../../www/py-ClientForm
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup>=3.0.5:../../www/py-beautifulsoup
DEPENDS+=	${PYPKGPREFIX}-mechanize>=0.1.11:../../www/py-mechanize
DEPENDS+=	${PYPKGPREFIX}-cssutils>=0.9.7:../../textproc/py-cssutils
# Let's depend on the ones we have in pkgsrc instead of the bundled ones.
DEPENDS+=	${PYPKGPREFIX}-Pdf-[0-9]*:../../print/py-Pdf
DEPENDS+=	${PYPKGPREFIX}-cherrypy-[0-9]*:../../www/py-cherrypy

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config pax
PYTHON_VERSIONS_ACCEPTED=	27
PYDISTUTILSPKG=	yes
PYSETUPOPTARGS=	# empty
PYSETUPINSTALLARGS=	--prefix=${PREFIX} --root=${DESTDIR:Q}${PREFIX}
WRKSRC=		${WRKDIR}/calibre

INSTALLATION_DIRS=	share/applications
INSTALLATION_DIRS=	share/icons
INSTALLATION_DIRS=	share/calibre/recipes

FIX_PYTHON+=	recipes/*.recipe
FIX_PYTHON+=	resources/catalog/*.py
FIX_PYTHON+=	resources/*.py
FIX_PYTHON+=	*.py
FIX_PYTHON+=	setup/*.py
FIX_PYTHON+=	setup/installer/*.py
FIX_PYTHON+=	setup/installer/linux/*.py
FIX_PYTHON+=	setup/installer/osx/*.py
FIX_PYTHON+=	setup/installer/osx/app/*.py
FIX_PYTHON+=	setup/installer/windows/*.py
FIX_PYTHON+=	src/calibre/*.py
FIX_PYTHON+=	src/calibre/customize/*.py
FIX_PYTHON+=	src/calibre/db/*.py
FIX_PYTHON+=	src/calibre/db/tests/*.py
FIX_PYTHON+=	src/calibre/devices/*.py
FIX_PYTHON+=	src/calibre/devices/android/*.py
FIX_PYTHON+=	src/calibre/devices/eslick/*.py
FIX_PYTHON+=	src/calibre/devices/folder_device/*.py
FIX_PYTHON+=	src/calibre/devices/iriver/*.py
FIX_PYTHON+=	src/calibre/devices/kobo/*.py
FIX_PYTHON+=	src/calibre/devices/prs505/*.py
FIX_PYTHON+=	src/calibre/devices/prst1/*.py
FIX_PYTHON+=	src/calibre/devices/teclast/*.py
FIX_PYTHON+=	src/calibre/ebooks/chm/*.py
FIX_PYTHON+=	src/calibre/ebooks/comic/*.py
FIX_PYTHON+=	src/calibre/ebooks/compression/*.py
FIX_PYTHON+=	src/calibre/ebooks/conversion/*.py
FIX_PYTHON+=	src/calibre/ebooks/djvu/*.py
FIX_PYTHON+=	src/calibre/ebooks/epub/fix/*.py
FIX_PYTHON+=	src/calibre/ebooks/epub/*.py
FIX_PYTHON+=	src/calibre/ebooks/html/*.py
FIX_PYTHON+=	src/calibre/ebooks/iterator/*.py
FIX_PYTHON+=	src/calibre/ebooks/lit/*.py
FIX_PYTHON+=	src/calibre/ebooks/lrf/html/*.py
FIX_PYTHON+=	src/calibre/ebooks/lrf/*.py
FIX_PYTHON+=	src/calibre/ebooks/lrf/pylrs/*.py
FIX_PYTHON+=	src/calibre/ebooks/markdown/extensions/*.py
FIX_PYTHON+=	src/calibre/ebooks/metadata/*.py
FIX_PYTHON+=	src/calibre/ebooks/metadata/book/*.py
FIX_PYTHON+=	src/calibre/ebooks/metadata/book/*.py
FIX_PYTHON+=	src/calibre/ebooks/metadata/sources/*.py
FIX_PYTHON+=	src/calibre/ebooks/mobi/*.py
FIX_PYTHON+=	src/calibre/ebooks/mobi/writer2/*.py
FIX_PYTHON+=	src/calibre/ebooks/odt/__init__.py
FIX_PYTHON+=	src/calibre/ebooks/oeb/transforms/*.py
FIX_PYTHON+=	src/calibre/ebooks/pdf/__init__.py
FIX_PYTHON+=	src/calibre/ebooks/pdf/reflow.py
FIX_PYTHON+=	src/calibre/ebooks/readability/*.py
FIX_PYTHON+=	src/calibre/ebooks/rtf/*.py
FIX_PYTHON+=	src/calibre/ebooks/rtf2xml/*.py
FIX_PYTHON+=	src/calibre/ebooks/snb/*.py
FIX_PYTHON+=	src/calibre/ebooks/textile/*.py
FIX_PYTHON+=	src/calibre/ebooks/txt/*.py
FIX_PYTHON+=	src/calibre/gui2/*.py
FIX_PYTHON+=	src/calibre/gui2/actions/*.py
FIX_PYTHON+=	src/calibre/gui2/add_wizard/*.py
FIX_PYTHON+=	src/calibre/gui2/catalog/*.py
FIX_PYTHON+=	src/calibre/gui2/convert/*.py
FIX_PYTHON+=	src/calibre/gui2/dialogs/*.py
FIX_PYTHON+=	src/calibre/gui2/library/*.py
FIX_PYTHON+=	src/calibre/gui2/metadata/*.py
FIX_PYTHON+=	src/calibre/gui2/preferences/*.py
FIX_PYTHON+=	src/calibre/gui2/progress_indicator/*.py
FIX_PYTHON+=	src/calibre/gui2/tag_browser/*.py
FIX_PYTHON+=	src/calibre/gui2/viewer/*.py
FIX_PYTHON+=	src/calibre/gui2/wizard/*.py
FIX_PYTHON+=	src/calibre/library/*.py
FIX_PYTHON+=	src/calibre/library/server/*.py
FIX_PYTHON+=	src/calibre/manual/*.py
FIX_PYTHON+=	src/calibre/manual/plugin_examples/helloworld/*.py
FIX_PYTHON+=	src/calibre/manual/plugin_examples/interface_demo/*.py
FIX_PYTHON+=	src/calibre/trac/*.py
FIX_PYTHON+=	src/calibre/translations/*.py
FIX_PYTHON+=	src/calibre/utils/*.py
FIX_PYTHON+=	src/calibre/utils/fonts/*.py
FIX_PYTHON+=	src/calibre/utils/ipc/*.py
FIX_PYTHON+=	src/calibre/utils/magick/*.py
FIX_PYTHON+=	src/calibre/utils/podofo/*.py
FIX_PYTHON+=	src/calibre/utils/pyconsole/*.py
FIX_PYTHON+=	src/calibre/utils/wmf/*.py
FIX_PYTHON+=	src/calibre/web/feeds/*.py
FIX_PYTHON+=	src/calibre/web/feeds/recipes/*.py
FIX_PYTHON+=	src/calibre/web/fetch/*.py
FIX_PYTHON+=	src/calibre/web/jsbrowser/*.py
FIX_PYTHON+=	src/templite/*.py

SUBST_CLASSES+=		prefix
SUBST_SED.prefix=	-e "s,^QMAKE =.*,QMAKE = '${PREFIX}/qt4/bin/qmake',"
SUBST_MESSAGE.prefix=	Fixing path to QMAKE
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	setup/build_environment.py

# This one is for /usr/bin/env python (or even /usr/bin/env Python or /usr/bin/python2)
SUBST_CLASSES+=		path
SUBST_SED.path=		-e "s,\#! */usr/bin/env *[Pp]ython[0-9.]*,\#!${PYTHONBIN},"
SUBST_MESSAGE.path=	Fixing path to python.
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	${FIX_PYTHON}

# These ones are for replacing python[0-9*] with PYTHONBIN
REPLACE_PYTHON+=	recipes/animal_politico.recipe
REPLACE_PYTHON+=	recipes/kompiutierra.recipe
REPLACE_PYTHON+=	recipes/trouw.recipe
REPLACE_PYTHON+=	src/calibre/ebooks/markdown/extensions/*.py
REPLACE_PYTHON+=	src/calibre/ebooks/metadata/odt.py
REPLACE_PYTHON+=	src/calibre/utils/*.py
REPLACE_PYTHON+=	src/odf/*.py

MAKE_ENV+=		FC_INC_DIR=${BUILDLINK_PREFIX.fontconfig}/include/fontconfig
MAKE_ENV+=		FC_LIB_DIR=${BUILDLINK_PREFIX.fontconfig}/lib
MAKE_ENV+=		PODOFO_INC_DIR=${BUILDLINK_PREFIX.podofo}/include/podofo
MAKE_ENV+=		PODOFO_LIB_DIR=${BUILDLINK_PREFIX.podofo}/lib
#MAKE_ENV+=		WITH_USB=no

# Let's depend on the ones we have in pkgsrc instead of the bundled ones.
pre-configure:
	cd ${WRKSRC} && rm -rf src/cherrypy src/pyPdf

post-install:
	cd ${WRKSRC}/recipes && pax -wr -pma *.recipe \
	    ${DESTDIR}${PREFIX}/share/calibre/recipes
	cd ${WRKSRC} && pax -wr -pma Changelog* README \
	    COPYRIGHT INSTALL LICENSE.* \
	    ${DESTDIR}${PREFIX}/share/doc/calibre

.include "../../lang/python/application.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/chmlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libusb+=	libusb>=0.1.12
.include "../../devel/libusb/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.ImageMagick+=	ImageMagick>=6.5.9
.include "../../graphics/ImageMagick/buildlink3.mk"
BUILDLINK_API_DEPENDS.pyimaging+=	${PYPKGPREFIX}-imaging>=1.1.6
.include "../../graphics/py-imaging/buildlink3.mk"
BUILDLINK_API_DEPENDS.libwmf+=	libwmf>=0.2.8
.include "../../graphics/libwmf/buildlink3.mk"
.include "../../lang/python/egg.mk"
_PYSETUPTOOLSINSTALLARGS=	# empty
# Get rid of --root=${DESTDIR}, use our own version from above instead.
# because the setup.py is not the standard one and behaves differently.
_PYSETUPINSTALLARGS=	${PYSETUPINSTALLARGS} ${PYSETUPOPTARGS} ${_PYSETUPTOOLSINSTALLARGS}
#.include "../../lang/python/extension.mk"
.include "../../print/podofo/buildlink3.mk"
# ??? BUILDLINK_API_DEPENDS.podofo+=	podofo>=0.8.2
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler-qt4+=	poppler-qt4>=0.12.0
.include "../../print/poppler-qt4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/hal/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-dbus+=	${PYPKGPREFIX}-dbus>=0.82.2
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-qt4+=	${PYPKGPREFIX}-qt4>=4.7.0
.include "../../x11/py-qt4/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-tools+=	qt4-tools>=4.7.0
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
