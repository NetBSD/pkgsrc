# $NetBSD: Makefile,v 1.131 2016/02/14 10:07:26 wiz Exp $

DISTNAME=	calibre-2.51.0
CATEGORIES=	misc
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=calibre/}
MASTER_SITES=	http://download.calibre-ebook.com/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.calibre-ebook.com/
COMMENT=	E-book library management application
LICENSE=	gnu-gpl-v3

#DEPENDS+=	help2man>=1.36.4:../../converters/help2man
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	xdg-utils>=1.0.2:../../misc/xdg-utils
#DEPENDS+=	poppler-utils-[0-9]*:../../print/poppler-utils
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.2.1:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup>=3.0.5:../../www/py-beautifulsoup
DEPENDS+=	${PYPKGPREFIX}-mechanize>=0.1.11nb1:../../www/py-mechanize
DEPENDS+=	${PYPKGPREFIX}-cssselect>=0.7.1:../../textproc/py-cssselect
DEPENDS+=	${PYPKGPREFIX}-cssutils>=0.9.9:../../textproc/py-cssutils
DEPENDS+=	${PYPKGPREFIX}-psutil>=0.6.1:../../sysutils/py-psutil
## Let's depend on the ones we have in pkgsrc instead of the bundled ones.
#DEPENDS+=	${PYPKGPREFIX}-Pdf-[0-9]*:../../print/py-Pdf
DEPENDS+=	${PYPKGPREFIX}-cherrypy-[0-9]*:../../www/py-cherrypy
DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib
#DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-netifaces>=0.8:../../net/py-netifaces
DEPENDS+=	${PYPKGPREFIX}-apsw>=3.7.17:../../databases/py-apsw

# dateutil>=1.4.1
# dns>=1.6.0
PYTHON_VERSIONED_DEPENDENCIES=	dateutil dns

EXTRACT_USING=  bsdtar

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config pax
PYTHON_VERSIONS_ACCEPTED=	27
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not ported as of 2.1.0; also: py-mechanize, py-beautifulsoup, py-imaging, py-netifaces
PYDISTUTILSPKG=	yes
PYSETUPOPTARGS=	# empty
PYSETUPINSTALLARGS=	--prefix=${PREFIX} --root=${DESTDIR:Q}${PREFIX}

INSTALLATION_DIRS=	share/applications
INSTALLATION_DIRS=	share/icons
INSTALLATION_DIRS=	share/calibre/recipes

FIX_PYTHON_PATHS+=	*.py
FIX_PYTHON_PATHS+=	recipes/*.recipe
FIX_PYTHON_PATHS+=	*/*.py
FIX_PYTHON_PATHS+=	*/*/*.py
FIX_PYTHON_PATHS+=	*/*/*/*.py
FIX_PYTHON_PATHS+=	*/*/*/*/*.py
FIX_PYTHON_PATHS+=	*/*/*/*/*/*.py
FIX_PYTHON_PATHS+=	*/*/*/*/*/*/*.py

SUBST_CLASSES+=		prefix
SUBST_SED.prefix=	-e "s,^QMAKE =.*,QMAKE = '${PREFIX}/qt5/bin/qmake',"
SUBST_MESSAGE.prefix=	Fixing path to QMAKE
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	setup/build_environment.py

# This one is for /usr/bin/env python (or even /usr/bin/env Python or /usr/bin/python2)
SUBST_CLASSES+=		path
SUBST_SED.path=		-e "s,\#! */usr/bin/env *[Pp]ython[0-9.]*,\#!${PYTHONBIN},"
SUBST_MESSAGE.path=	Fixing path to python.
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	${FIX_PYTHON_PATHS}

REPLACE_BASH+=		resources/calibre-portable.sh

# These ones are for replacing python[0-9*] with PYTHONBIN
REPLACE_PYTHON+=	recipes/animal_politico.recipe
REPLACE_PYTHON+=	recipes/respekt_magazine.recipe
REPLACE_PYTHON+=	recipes/respekt_web.recipe
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
MAKE_ENV+=		SIP_BIN=${BUILDLINK_PREFIX.py-sip}/bin/sip${PYVERSSUFFIX}
#MAKE_ENV+=		WITH_USB=no

# Let's depend on the ones we have in pkgsrc instead of the bundled ones.
pre-configure:
	cd ${WRKSRC} && rm -rf src/cherrypy src/pyPdf src/html5lib src/chardet

# Turn off x bits on non-executable files.
post-extract:
	find  ${WRKSRC}/src/calibre/devices ${WRKSRC}/src/calibre/ebooks ${WRKSRC}/src/calibre/web -name '*.py' -exec chmod a-x \{} \;
	find  ${WRKSRC}/resources/images/mimetypes  -name '*.png' -exec chmod a-x \{} \;
	chmod a-x ${WRKSRC}/src/calibre/utils/Zeroconf.py
	chmod a-x ${WRKSRC}/src/calibre/utils/smtplib.py

# not sure why libheadless installed into wrong directory
# side effect of patch-setup_extensions.py?
post-install:
	cd ${WRKSRC}/recipes && pax -wr -pma *.recipe \
	    ${DESTDIR}${PREFIX}/share/calibre/recipes
	cd ${WRKSRC} && pax -wr -pma Changelog* README.md \
	    COPYRIGHT INSTALL LICENSE.* \
	    ${DESTDIR}${PREFIX}/share/doc/calibre
	cd ${DESTDIR}${PREFIX} && ${MV} lib/calibre/calibre/plugins/.libs/libheadless.so lib/calibre/calibre/plugins/libheadless.so
	${RM} ${DESTDIR}${PREFIX}/bin/calibre-uninstall

.include "../../lang/python/application.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../databases/sqlite3/buildlink3.mk"
BUILDLINK_API_DEPENDS.chmlib+=	chmlib>=0.40
.include "../../devel/chmlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libmtp+=	libmtp>=1.1.5
.include "../../devel/libmtp/buildlink3.mk"
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
BUILDLINK_API_DEPENDS.podofo+=	podofo>=0.8.2
.include "../../print/podofo/buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler+=	poppler>=0.20.2
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-qt5/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/hal/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-dbus+=	${PYPKGPREFIX}-dbus>=0.82.2
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-qt5+=	${PYPKGPREFIX}-qt5>=5.4
.include "../../x11/py-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
