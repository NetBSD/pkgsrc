# $NetBSD: Makefile,v 1.4 2020/05/15 14:59:53 micha Exp $

DISTNAME=	eureka-1.27b-source
# Some macOS patches were added after the release of 1.27 but unfortunately
# the archive name was not changed (pkgsrc used 1.27.1 for this version).
# The second patch release is called 1.27b, we use version 1.27.2 for it.
# Switch back to upstream naming scheme for next major/minor release.
PKGNAME=	${DISTNAME:S/-source//:S/b/.2/}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=eureka-editor/}

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/eureka-editor/
COMMENT=	Doom/Heretic/Hexen map editor
LICENSE=	gnu-gpl-v2

# Error on SmartOS 20200130T160054Z/x86_64:
# [...]
# src/e_basis.cc:1200:57: error: expected ',' or '...' before numeric constant
#  1200 | static void ChecksumSector(crc32_c& crc, const Sector * SEC)
#       |                                                         ^~~
# src/e_basis.cc: In function 'void ChecksumSector(crc32_c&, const Sector*)':
# src/e_basis.cc:1202:12: error: base operand of '->' is not a pointer
#  1202 |  crc += SEC->floorh;
#       |            ^~
BROKEN_ON_PLATFORM=	SunOS-*-*

# Makefile declares "-std=c++03"
USE_LANGUAGES=	c++03
USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/eureka-1.27b-source

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

.include "../../mk/bsd.pkg.mk"
