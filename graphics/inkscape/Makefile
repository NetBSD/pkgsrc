# $NetBSD: Makefile,v 1.195 2019/10/19 12:46:05 nia Exp $

DISTNAME=	inkscape-0.92.4
PKGREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	https://media.inkscape.org/dl/resources/file/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.inkscape.org/
COMMENT=	Scalable Vector Graphics (SVG) editor
LICENSE=	gnu-gpl-v2

.if !exists(/usr/bin/iconv)
BUILD_DEPENDS+=	libiconv-[0-9]*:../../converters/libiconv
.endif
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
# for inkex.py, needed by most python extension scripts
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

EXTRACT_USING=		bsdtar
GCC_REQD+=		4.5.2

USE_CMAKE=		yes
USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		intltool msgfmt msgmerge perl:run pkg-config

REPLACE_PERL+=		fix-roff-punct
REPLACE_PERL+=		share/extensions/*.p[lm]
REPLACE_PERL+=		share/templates/create_defaults.pl

BUILDLINK_API_DEPENDS.boehm-gc+=	boehm-gc>=6.4
BUILDLINK_API_DEPENDS.poppler+=		poppler>=0.5.9

UNLIMIT_RESOURCES=	datasize

LDFLAGS.DragonFly=	-lX11

SUBST_CLASSES+=		pypath
SUBST_STAGE.pypath=	pre-configure
SUBST_FILES.pypath=	src/extension/implementation/script.cpp
SUBST_VARS.pypath=	PYTHONBIN

SUBST_CLASSES+=		pycmd
SUBST_STAGE.pycmd=	pre-configure
SUBST_MESSAGE.pycmd=	Replacing COMMAND python in CMakeFiles.
SUBST_FILES.pycmd+=	share/filters/CMakeLists.txt
SUBST_FILES.pycmd+=	share/palettes/CMakeLists.txt
SUBST_FILES.pycmd+=	share/patterns/CMakeLists.txt
SUBST_FILES.pycmd+=	share/symbols/CMakeLists.txt
SUBST_FILES.pycmd+=	share/templates/CMakeLists.txt
SUBST_SED.pycmd=	-e "s,COMMAND python,COMMAND ${PYTHONBIN},g"

SUBST_CLASSES+=		bool
SUBST_STAGE.bool=	pre-configure
SUBST_FILES.bool+=	src/extension/internal/pdfinput/pdf-parser.*
SUBST_SED.bool=		-e 's|gTrue|true|g'
SUBST_SED.bool+=	-e 's|gFalse|false|g'
SUBST_SED.bool+=	-e 's|GBool|bool|g'

REPLACE_PYTHON+=	cxxtest/cxxtestgen.py
REPLACE_PYTHON+=	share/extensions/*.py
REPLACE_PYTHON+=	share/extensions/Barcode/*.py
REPLACE_PYTHON+=	share/extensions/ink2canvas/*.py
REPLACE_PYTHON+=	share/extensions/test/*.test.py

CHECK_INTERPRETER_SKIP+=share/inkscape/extensions/genpofiles.sh
CHECK_INTERPRETER_SKIP+=share/inkscape/extensions/simplepath.rb
CHECK_PORTABILITY_SKIP+=packaging/macosx/Resources/bin/inkscape
CHECK_PORTABILITY_SKIP+=packaging/macosx/ScriptExec/launcher-quartz-no-macintegration.sh

.include "options.mk"

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
CMAKE_ARGS+=	-DIntl_INCLUDE_DIR=${BUILDLINK_PREFIX.gettext}/include
.endif

BUILDLINK_API_DEPENDS.poppler-includes+= poppler-includes>=0.12.2
BUILDLINK_API_DEPENDS.boehm-gc+=	boehm-gc>=7.4
.include "../../converters/libcdr/buildlink3.mk"
.include "../../converters/libvisio/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/potrace/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
