# $NetBSD: Makefile,v 1.227 2021/04/09 11:18:24 adam Exp $

DISTNAME=	inkscape-1.0.2
CATEGORIES=	graphics
MASTER_SITES=	https://media.inkscape.org/dl/resources/file/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://www.inkscape.org/
COMMENT=	Scalable Vector Graphics (SVG) editor
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/inkscape-1.0.2_2021-01-15_e86c870879

.if !exists(/usr/bin/iconv)
BUILD_DEPENDS+=	libiconv-[0-9]*:../../converters/libiconv
.endif
DEPENDS+=	adwaita-icon-theme>0:../../graphics/adwaita-icon-theme
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
# for inkex.py, needed by most python extension scripts
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
# for desktop
TOOL_DEPENDS+=	gettext-tools-[0-9]*:../../devel/gettext-tools
TOOLS_PLATFORM.msgfmt= # empty

EXTRACT_USING=		bsdtar
GCC_REQD+=		4.5.2

# This should be resolved in CMakeLists.txt.
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/inkscape

USE_CMAKE=		yes
USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		intltool msgfmt msgmerge perl pkg-config

REPLACE_PERL+=		man/fix-roff-punct
REPLACE_PERL+=		share/extensions/*.p[lm]
REPLACE_PERL+=		share/templates/create_defaults.pl

UNLIMIT_RESOURCES=	datasize

LDFLAGS.DragonFly=	-lX11

PYTHON_VERSIONS_INCOMPATIBLE=	27

SUBST_CLASSES+=		pypath
SUBST_STAGE.pypath=	pre-configure
SUBST_FILES.pypath=	src/extension/implementation/script.cpp
SUBST_VARS.pypath=	PYTHONBIN

SUBST_CLASSES+=		pycmd
SUBST_STAGE.pycmd=	pre-configure
SUBST_MESSAGE.pycmd=	Replacing COMMAND python in CMakeFiles.
SUBST_FILES.pycmd+=	share/*/CMakeLists.txt
SUBST_SED.pycmd=	-e "s,COMMAND python3,COMMAND ${PYTHONBIN},g"

REPLACE_PYTHON+=	share/extensions/*.py

CHECK_INTERPRETER_SKIP+=	share/inkscape/extensions/genpofiles.sh
CHECK_INTERPRETER_SKIP+=	share/inkscape/extensions/simplepath.rb
CHECK_PORTABILITY_SKIP+=	packaging/macosx/Resources/bin/inkscape
CHECK_PORTABILITY_SKIP+=	packaging/macosx/ScriptExec/launcher-quartz-no-macintegration.sh

CMAKE_ARGS+=	-DINKSCAPE_INSTALL_LIBDIR=${PREFIX}/lib
CMAKE_ARGS+=	-DPACKAGE_LOCALE_DIR=${PREFIX}/${PKGLOCALEDIR}/locale

MANCOMPRESSED=	yes

.include "options.mk"

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
CMAKE_ARGS+=	-DIntl_INCLUDE_DIR=${BUILDLINK_PREFIX.gettext}/include
.endif

post-extract:
	${RM} -r ${WRKSRC}/share/extensions/.pytest_cache

# There exists some race condition in create_default_templates.py that
# makes default.es_MX.svg sometimes not get installed.
# (gettext translation file dependency not correctly expressed in cmake?)
# Run the script post-build to ensure all files are generated.
post-build:
	cd ${WRKSRC} && ${PYTHONBIN} share/templates/create_default_templates.py . .

BUILDLINK_API_DEPENDS.boehm-gc+=	boehm-gc>=7.4
.include "../../converters/libcdr/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.include "../../converters/libvisio/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/gdl/buildlink3.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/potrace/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/double-conversion/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/gtkspell3/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gtkmm3/buildlink3.mk"
.if ${PKG_BUILD_OPTIONS.gtk3:Mquartz}
.include "../../x11/gtk-mac-integration/buildlink3.mk"
.else
.include "../../x11/libXext/buildlink3.mk"
.endif
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/application.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
