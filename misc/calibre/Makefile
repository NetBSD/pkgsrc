# $NetBSD: Makefile,v 1.4 2009/11/18 17:41:20 wiz Exp $
#

DISTNAME=	calibre-0.6.24
CATEGORIES=	misc
MASTER_SITES=	http://calibre.kovidgoyal.net/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://calibre.kovidgoyal.net/
COMMENT=	E-book library management application
LICENSE=	gnu-gpl-v3

DEPENDS+=	help2man>=1.36.4:../../converters/help2man
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	xdg-utils>=1.0.2:../../misc/xdg-utils
DEPENDS+=	poppler-utils-[0-9]*:../../print/poppler-utils
DEPENDS+=	${PYPKGPREFIX}-dns>=1.6.0:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.1.5:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.4.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-ClientForm-[0-9]*:../../www/py-ClientForm
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup>=3.0.5:../../www/py-beautifulsoup
DEPENDS+=	${PYPKGPREFIX}-mechanize>=0.1.11:../../www/py-mechanize

#PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
PYTHON_VERSIONS_ACCEPTED=	26
PYDISTUTILSPKG=	yes
PYSETUPOPTARGS=	# empty
PYSETUPINSTALLARGS=	--prefix=${PREFIX}
WRKSRC=		${WRKDIR}/calibre
INSTALLATION_DIRS=	share/applications
INSTALLATION_DIRS=	share/icons

REPLACE_PYTHON=		src/calibre/ebooks/metadata/odt.py
REPLACE_PYTHON+=	src/odf/element.py
REPLACE_PYTHON+=	src/odf/elementtypes.py
REPLACE_PYTHON+=	src/odf/load.py
REPLACE_PYTHON+=	src/odf/manifest.py
REPLACE_PYTHON+=	src/odf/odf2xhtml.py
REPLACE_PYTHON+=	src/odf/odfmanifest.py
REPLACE_PYTHON+=	src/odf/thumbnail.py
REPLACE_PYTHON+=	src/odf/userfield.py
REPLACE_PYTHON+=	resources/recipes/fokkeensukke.recipe
REPLACE_PYTHON+=	resources/recipes/trouw.recipe

SUBST_CLASSES+=		prefix
SUBST_SED.prefix=	-e "s,^QMAKE =.*,QMAKE = '${PREFIX}/qt4/bin/qmake',"
SUBST_MESSAGE.prefix=	Fixing path to QMAKE
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	setup/build_environment.py

MAKE_ENV+=		FC_INC_DIR=${BUILDLINK_PREFIX.fontconfig}/include/fontconfig
MAKE_ENV+=		FC_LIB_DIR=${BUILDLINK_PREFIX.fontconfig}/lib
MAKE_ENV+=		PODOFO_INC_DIR=${BUILDLINK_PREFIX.podofo}/include/podofo
MAKE_ENV+=		PODOFO_LIB_DIR=${BUILDLINK_PREFIX.podofo}/lib
#MAKE_ENV+=		XDG_UTILS_DEBUG_LEVEL=100

BUILDLINK_API_DEPENDS.libusb+=	libusb>=0.1.12
.include "../../devel/libusb/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.ImageMagick+=	ImageMagick>=6.3.5
.include "../../graphics/ImageMagick/buildlink3.mk"
BUILDLINK_API_DEPENDS.pyimaging+=	${PYPKGPREFIX}-imaging>=1.1.6
.include "../../graphics/py-imaging/buildlink3.mk"
BUILDLINK_API_DEPENDS.libwmf+=	libwmf>=0.2.8
.include "../../graphics/libwmf/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
_PYSETUPTOOLSINSTALLARGS=	# empty
#.include "../../lang/python/extension.mk"
.include "../../print/podofo/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler-qt4+=	poppler-qt4>=0.10.6
.include "../../print/poppler-qt4/buildlink3.mk"
.include "../../sysutils/hal/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-dbus+=	${PYPKGPREFIX}-dbus>=0.82.2
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-qt4+=	${PYPKGPREFIX}-qt4>=4.5.1
.include "../../x11/py-qt4/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-tools+=	qt4-tools>=4.5.1
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
