# $NetBSD: Makefile,v 1.1.1.1 2009/01/17 22:18:25 wiz Exp $
#

DISTNAME=	calibre-0.4.128
CATEGORIES=	misc
MASTER_SITES=	http://calibre.kovidgoyal.net/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://calibre.kovidgoyal.net/
COMMENT=	E-book library management application

DEPENDS+=	help2man>=1.36.4:../../converters/help2man
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	ImageMagick>=6.3.5:../../graphics/ImageMagick
DEPENDS+=	xdg-utils>=1.0.2:../../misc/xdg-utils
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.0.5:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-ClientForm-[0-9]*:../../www/py-ClientForm
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup>=3.0.5:../../www/py-beautifulsoup
DEPENDS+=	${PYPKGPREFIX}-mechanize>=0.1.8:../../www/py-mechanize

USE_LANGUAGES=	c c++
PYTHON_VERSIONS_ACCEPTED=	25
PYDISTUTILSPKG=	yes

REPLACE_PYTHON=		src/calibre/ebooks/metadata/odt.py
REPLACE_PYTHON+=	src/odf/element.py
REPLACE_PYTHON+=	src/odf/elementtypes.py
REPLACE_PYTHON+=	src/odf/load.py
REPLACE_PYTHON+=	src/odf/manifest.py
REPLACE_PYTHON+=	src/odf/odf2xhtml.py
REPLACE_PYTHON+=	src/odf/odfmanifest.py
REPLACE_PYTHON+=	src/odf/thumbnail.py
REPLACE_PYTHON+=	src/odf/userfield.py

SUBST_CLASSES+=		prefix
SUBST_SED.prefix=	-e "s,^QMAKE =.*,QMAKE = '${PREFIX}/qt4/bin/qmake',"
SUBST_MESSAGE.prefix=	Fixing path to QMAKE
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	pyqtdistutils.py

SUBST_CLASSES+=		install
SUBST_SED.install=	-e "s,/usr/share/man,${PREFIX}/${PKGMANDIR},"
SUBST_MESSAGE.install=	Fixing installation paths
SUBST_STAGE.install=	post-patch
SUBST_FILES.install=	src/calibre/linux.py

BUILDLINK_API_DEPENDS.libusb+=	libusb>=0.1.12
.include "../../devel/libusb/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../sysutils/hal/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-dbus+=	${PYPKGPREFIX}-dbus>=0.82.2
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
