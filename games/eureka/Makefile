# $NetBSD: Makefile,v 1.11 2024/07/15 13:08:44 micha Exp $

DISTNAME=	eureka-2.0.2
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=ioan-chera/}
GITHUB_PROJECT=	eureka-editor
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://eureka-editor.sourceforge.net/
COMMENT=	Doom/Heretic/Hexen map editor
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_CC_FEATURES+=	c11
# charconv is not used by package, but needs GCC 8 (GCC 7.5 is not good enough)
USE_CXX_FEATURES+=	c++17 charconv has_include unique_ptr

CMAKE_ARGS+=		-DENABLE_UNIT_TESTS=off

# DOOMWADDIR is intentionally shared with other Doom packages
DOOMWADDIR=		share/doom
INSTALLATION_DIRS=	bin

# Modify internal search path to check ${PREFIX}/share hierarchy first
SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	do-configure
SUBST_MESSAGE.prefix=	Preparing main.cc ...
SUBST_FILES.prefix=	src/main.cc
SUBST_SED.prefix=	-e 's,PKGSRC_PREFIX,${PREFIX},'

# Modify internal search path for DOOMWADDIR (if environment variable not set)
SUBST_CLASSES+=		dwd
SUBST_STAGE.dwd=	do-configure
SUBST_MESSAGE.dwd=	Preparing m_files.cc ...
SUBST_FILES.dwd=	src/m_files.cc
SUBST_SED.dwd=		-e 's,PKGSRC_DOOMWADDIR,${PREFIX}/${DOOMWADDIR},'

.include "options.mk"

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.3
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

.include "../../devel/cmake/build.mk"

.include "../../mk/bsd.pkg.mk"
