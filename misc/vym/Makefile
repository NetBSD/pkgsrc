# $NetBSD: Makefile,v 1.87 2024/12/18 12:31:30 nia Exp $

DISTNAME=		vym-2.9.31
PKGREVISION=		4
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
USE_TOOLS+=		bash:run pkg-config gmake

MANCOMPRESSED=		yes

REPLACE_BASH+=		scripts/vivym

CHECK_INTERPRETER_SKIP=	share/vym/scripts/vym-addmail.rb

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/vym

SUBST_CLASSES+=		flags
SUBST_STAGE.flags=	pre-configure
SUBST_MESSAGE.flags=	Fix path to flags
SUBST_FILES.flags=	src/main.cpp src/mainwindow.cpp
SUBST_VARS.flags=	PREFIX

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

.include "../../devel/cmake/build.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../lang/ruby/replace.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
