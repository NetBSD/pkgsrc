# $NetBSD: Makefile,v 1.64 2024/05/29 16:32:21 adam Exp $

DISTNAME=	codelite-17.0.0
PKGREVISION=	6
CATEGORIES=	editors x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=eranif/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codelite.org/
COMMENT=	Cross platform C/C++/PHP and Node.js IDE written in C++
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME:R}

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config bash gmake:run
USE_CXX_FEATURES=	c++11

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CXX_STANDARD=11
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CXX_STANDARD_REQUIRED:BOOL=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CXX_EXTENSIONS:BOOL=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_PRECOMPILE_HEADERS:BOOL=ON

.include "../../mk/bsd.prefs.mk"

# Likely needed because pango's pkgconfig CFLAGS aren't being applied.
CXXFLAGS+=		-I${BUILDLINK_DIR}/include/harfbuzz

CHECK_PORTABILITY_SKIP+=	sdk/wxsqlite3/configure
CHECK_PORTABILITY_SKIP+=	InnoSetup/output/finalize-upload.sh
CHECK_PORTABILITY_SKIP+=	wxcrafter/pack-osx.sh

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
SUBST_FILES.fix-bash+=		Docker/clDockerDriver.cpp
SUBST_SED.fix-bash+=		-e 's,/bin/bash,${BASH},g'

REPLACE_BASH+=		ctags/misc/review
REPLACE_BASH+=		ctags/Units/parser-sh.r/array-alike-function.d/input.bash
REPLACE_BASH+=		ctags/Units/parser-sh.r/sh-herestring.d/input.sh
REPLACE_BASH+=		docs/docs/deploy.sh
REPLACE_BASH+=		weekly/make-weekly-common
REPLACE_BASH+=		weekly/make-weekly-linux
REPLACE_BASH+=		weekly/make-weekly-macos
REPLACE_BASH+=		weekly/make-weekly-msw
REPLACE_NODEJS+=	LanguageServer/codelite-lsp/codelite-lsp-helper
REPLACE_PYTHON+=	Runtime/codelite-remote
REPLACE_PYTHON+=	codelite_open_helper.py

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/codelite

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--disable-new-dtags

TOOL_DEPENDS+=	dos2unix-[0-9]*:../../converters/dos2unix

pre-patch:
	dos2unix ${WRKSRC}/CodeLite/cpp_expr_parser.cpp
	dos2unix ${WRKSRC}/CodeLite/cpp_func_parser.cpp
	dos2unix ${WRKSRC}/CodeLite/pp.cpp
	dos2unix ${WRKSRC}/CodeLite/scope_parser.cpp
	dos2unix ${WRKSRC}/CodeLite/typedef_parser.cpp
	dos2unix ${WRKSRC}/CodeLite/var_parser.cpp
	dos2unix ${WRKSRC}/LiteEditor/tabgroupmanager.h
	dos2unix ${WRKSRC}/Plugin/clPluginsFindBar.h

PLIST_VARS+=		notdarwin
.if ${OPSYS} != "Darwin"
PLIST.notdarwin=	YES
.endif

.include "../../devel/cmake/build.mk"
.include "../../lang/nodejs/application.mk"
.include "../../lang/nodejs/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../textproc/uchardet/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../x11/wxGTK32/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
