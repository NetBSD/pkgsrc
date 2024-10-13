# $NetBSD: Makefile,v 1.83 2024/10/13 09:45:24 bsiegert Exp $

DISTNAME=		vym-2.9.31
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GITHUB:=insilmaril/}
GITHUB_TAG=		da30b21109544ee0596ebf4d9738b5fed69b3cc4

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.insilmaril.de/vym/
COMMENT=		Generate and manipulate maps which show your thoughts
LICENSE=		gnu-gpl-v2

DEPENDS+=		xdg-utils-[0-9]*:../../misc/xdg-utils
DEPENDS+=		unzip-[0-9]*:../../archivers/unzip
DEPENDS+=		zip-[0-9]*:../../archivers/zip

USE_LANGUAGES=		c c++
USE_TOOLS+=		bash:run pkg-config gmake gzip

REPLACE_BASH+=		scripts/vivym

CHECK_INTERPRETER_SKIP=	share/vym/scripts/vym-addmail.rb

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/vym

SUBST_CLASSES+=		flags
SUBST_STAGE.flags=	pre-configure
SUBST_MESSAGE.flags=	Fix path to flags
SUBST_FILES.flags=	src/main.cpp src/mainwindow.cpp
SUBST_VARS.flags=	PREFIX

SUBST_CLASSES+=		man-gz
SUBST_STAGE.man-gz=	pre-configure
SUBST_MESSAGE.man-gz=	Fix installing gzipped man page
SUBST_FILES.man-gz=	CMakeLists.txt
SUBST_SED.man-gz=	-e 's;doc/vym.1.gz;doc/vym.1;g'

# 'CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_MANDIR=man/man1' seems to be ignored
SUBST_CLASSES+=			cmake-mandir
SUBST_STAGE.cmake-mandir=	pre-configure
SUBST_MESSAGE.cmake-mandir=	Fix man page path
SUBST_FILES.cmake-mandir=	CMakeLists.txt
SUBST_SED.cmake-mandir=		-e 's;\$${CMAKE_INSTALL_MANDIR};$$\{CMAKE_INSTALL_PREFIX\}/man/man1;g'

SUBST_CLASSES+=		man-bin
SUBST_STAGE.man-bin=	post-build
SUBST_MESSAGE.man-bin=	Fixing bin path in man page
SUBST_FILES.man-bin=	doc/vym.1
SUBST_SED.man-bin=	-e 's;/usr/bin/;${PREFIX}/bin/;g'

SUBST_CLASSES+=		man-doc
SUBST_STAGE.man-doc=	post-build
SUBST_MESSAGE.man-doc=	Fixing doc path in man page
SUBST_FILES.man-doc=	doc/vym.1
SUBST_SED.man-doc=	-e 's;/usr/share/doc/packages/vym;${PREFIX}/share/doc/vym;g'

SUBST_CLASSES+=		pdf-path
SUBST_STAGE.pdf-path=	pre-configure
SUBST_MESSAGE.pdf-path=	Fix installing pdf files in share/doc/vym/doc
SUBST_FILES.pdf-path=	CMakeLists.txt
SUBST_SED.pdf-path=	-e 's;doc DESTINATION;doc/ DESTINATION;g'

# installation fails
# TODO: report upstream
CMAKE_BUILD_DIR=		.
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_BUILD_TYPE="Release"
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_INSTALL_PREFIX=${PREFIX}
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_INSTALL_DATADIR=share/vym
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_INSTALL_DATAROOTDIR=share/vym
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_INSTALL_DOCDIR=share/doc/vym
#CMAKE_CONFIGURE_ARGS+=		-DCMAKE_INSTALL_MANDIR=man/man1

post-extract:
	${GZIP_CMD} -d ${WRKSRC}/doc/vym.1.gz

.include "../../devel/cmake/build.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../lang/ruby/replace.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
