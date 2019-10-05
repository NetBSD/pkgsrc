# $NetBSD: Makefile,v 1.25 2019/10/05 14:23:05 nia Exp $

DISTNAME=	codelite-13.0
PKGREVISION=	1
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

# For some reason CMAKE_ARGS.NetBSD+=-DIS_NETBSD:STRING=1 doesn't work for me
.include "../../mk/bsd.prefs.mk"

# Likely needed because pango's pkgconfig CFLAGS aren't being applied.
CXXFLAGS+=		-I${BUILDLINK_DIR}/include/harfbuzz

CHECK_PORTABILITY_SKIP+=	sdk/wxsqlite3/configure

.if ${OPSYS} == "NetBSD"
CMAKE_ARGS+=			-DIS_NETBSD:STRING=1
SUBST_CLASSES+=			ena-netbsd
SUBST_STAGE.ena-netbsd=		pre-configure
SUBST_MESSAGE.ena-netbsd=	Enable NetBSD
SUBST_FILES.ena-netbsd=		CMakeLists.txt
SUBST_SED.ena-netbsd+=		-e 's,IS_NETBSD 0,IS_NETBSD 1,g'
.endif

SUBST_CLASSES+=			fix-bash
SUBST_STAGE.fix-bash=		pre-configure
SUBST_MESSAGE.fix-bash=		Fix bash path
SUBST_FILES.fix-bash=		CodeLite/TerminalEmulator.cpp
SUBST_FILES.fix-bash+=		CodeLite/fileextmanager.cpp
SUBST_FILES.fix-bash+=		Runtime/codelite_xterm
SUBST_FILES.fix-bash+=		cmake/Modules/OSXInstall.cmake
SUBST_SED.fix-bash+=		-e 's,/bin/bash,${BASH},g'

SUBST_CLASSES+=			fix-man-path
SUBST_STAGE.fix-man-path=	pre-configure
SUBST_MESSAGE.fix-man-path=	Fix man path
SUBST_FILES.fix-man-path=	LiteEditor/CMakeLists.txt
SUBST_SED.fix-man-path+=	-e 's,${CL_PREFIX}/share/man,${CL_PREFIX}/${PKGMANDIR},g'

REPLACE_BASH+=		Runtime/clg++
REPLACE_BASH+=		Runtime/clgcc
REPLACE_BASH+=		Runtime/codelite_xterm
REPLACE_BASH+=		codelite-icons-dark/pack-icons.sh
REPLACE_BASH+=		codelite-icons-fresh-farm/pack-icons.sh
REPLACE_BASH+=		codelite-icons/pack-icons.sh
REPLACE_BASH+=		codelitephp/resources/pack-resources.sh
REPLACE_BASH+=		make-weekly
REPLACE_BASH+=		svgs/code-completion/convert-svg-to-png.sh
REPLACE_BASH+=		svgs/convert-single-file.sh
REPLACE_BASH+=		svgs/convert-svg-to-png.sh
REPLACE_BASH+=		svgs/create-logo-root.sh
REPLACE_BASH+=		svgs/create-logo.sh
REPLACE_BASH+=		svgs/find-bar/convert-svg-to-png.sh
REPLACE_NODEJS+=	LanguageServer/codelite-lsp/codelite-lsp-helper
REPLACE_PYTHON+=	codelite_open_helper.py

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/codelite

.include "../../lang/nodejs/application.mk"
.include "../../lang/nodejs/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
