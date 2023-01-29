# $NetBSD: Makefile,v 1.7 2023/01/29 21:16:09 ryoon Exp $

DISTNAME=	eureka-1.27b-source
# Some macOS patches were added after the release of 1.27 but unfortunately
# the archive name was not changed (pkgsrc used 1.27.1 for this version).
# The second patch release is called 1.27b, we use version 1.27.2 for it.
# Switch back to upstream naming scheme for next major/minor release.
PKGNAME=	${DISTNAME:S/-source//:S/b/.2/}
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=eureka-editor/}

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/eureka-editor/
COMMENT=	Doom/Heretic/Hexen map editor
LICENSE=	gnu-gpl-v2

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
