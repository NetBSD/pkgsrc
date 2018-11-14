# $NetBSD: Makefile,v 1.16 2018/11/14 22:21:22 kleink Exp $

DISTNAME=	codelite-9.1
PKGREVISION=	14
CATEGORIES=	editors x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=eranif/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/eranif/codelite/
COMMENT=	Cross platform C/C++/PHP and Node.js IDE written in C++
LICENSE=	gnu-gpl-v2

USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config bash

CMAKE_ARGS+=		-DPREFIX:STRING=${PREFIX}

# For some reason CMAKE_ARGS.NetBSD+=-DIS_NETBSD:STRING=1 doesn't work for me
.include "../../mk/bsd.prefs.mk"

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
SUBST_FILES.fix-bash=		CodeLite/TerminalEmulator.cpp
SUBST_FILES.fix-bash+=		CodeLite/fileextmanager.cpp
SUBST_FILES.fix-bash+=		Runtime/codelite_xterm
SUBST_FILES.fix-bash+=		cmake/Modules/OSXInstall.cmake
SUBST_SED.fix-bash+=		-e 's,/bin/bash,${BASH},g'

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

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/codelite

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
