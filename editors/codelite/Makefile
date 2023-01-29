# $NetBSD: Makefile,v 1.50 2023/01/29 21:15:53 ryoon Exp $

DISTNAME=	codelite-16.0
GITHUB_TAG=	16.0.0-1
PKGREVISION=	3
CATEGORIES=	editors x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=eranif/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codelite.org/
COMMENT=	Cross platform C/C++/PHP and Node.js IDE written in C++
LICENSE=	gnu-gpl-v2

USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config bash

CMAKE_ARGS+=		-DPREFIX:STRING=${PREFIX}

.include "../../mk/bsd.prefs.mk"

# Likely needed because pango's pkgconfig CFLAGS aren't being applied.
CXXFLAGS+=		-I${BUILDLINK_DIR}/include/harfbuzz

CHECK_PORTABILITY_SKIP+=	sdk/wxsqlite3/configure
CHECK_PORTABILITY_SKIP+=	InnoSetup/output/finalize-upload.sh
CHECK_PORTABILITY_SKIP+=	wxcrafter/pack-osx.sh

.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=			ena-netbsd
SUBST_STAGE.ena-netbsd=		pre-configure
SUBST_MESSAGE.ena-netbsd=	Enable NetBSD
SUBST_FILES.ena-netbsd=		CMakeLists.txt
SUBST_SED.ena-netbsd+=		-e 's,IS_NETBSD 0,IS_NETBSD 1,g'
.endif

SUBST_CLASSES+=			fix-bash
SUBST_STAGE.fix-bash=		pre-configure
SUBST_MESSAGE.fix-bash=		Fix bash path
SUBST_FILES.fix-bash+=		CodeLite/TerminalEmulator.cpp
SUBST_FILES.fix-bash+=		CodeLite/clConsoleBash.cpp
SUBST_FILES.fix-bash+=		CodeLite/clConsoleGnomeTerminal.cpp
SUBST_FILES.fix-bash+=		CodeLite/clConsoleRXVTerminal.cpp
SUBST_FILES.fix-bash+=		CodeLite/fileutils.cpp
SUBST_FILES.fix-bash+=		Plugin/custombuildrequest.cpp
SUBST_FILES.fix-bash+=		Plugin/pipedprocess.cpp
SUBST_FILES.fix-bash+=		Plugin/wxterminal.cpp
SUBST_FILES.fix-bash+=		Remoty/RemotyWorkspace.cpp
SUBST_FILES.fix-bash+=		cmake/Modules/UtilsHelper.cmake
SUBST_FILES.fix-bash+=		codelite_terminal/wxTerminalCtrl.cpp
SUBST_FILES.fix-bash+=		ctagsd/lib/Settings.cpp
SUBST_SED.fix-bash+=		-e 's,/bin/bash,${BASH},g'

SUBST_CLASSES+=			fix-man-path
SUBST_STAGE.fix-man-path=	pre-configure
SUBST_MESSAGE.fix-man-path=	Fix man path
SUBST_FILES.fix-man-path=	LiteEditor/CMakeLists.txt
SUBST_SED.fix-man-path+=	-e 's,${CL_PREFIX}/share/man,${CL_PREFIX}/${PKGMANDIR},g'

REPLACE_BASH+=		docs/docs/deploy.sh
REPLACE_BASH+=		make-weekly
REPLACE_NODEJS+=	LanguageServer/codelite-lsp/codelite-lsp-helper
REPLACE_PYTHON+=	Runtime/codelite-remote
REPLACE_PYTHON+=	codelite_open_helper.py

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/codelite

BUILDLINK_TRANSFORM+=	opt:-std=c++11:-std=gnu++11 # alloca

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--disable-new-dtags

.include "../../lang/nodejs/application.mk"
.include "../../lang/nodejs/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../textproc//uchardet/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../x11/wxGTK31/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
