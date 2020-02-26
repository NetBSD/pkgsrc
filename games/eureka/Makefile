# $NetBSD: Makefile,v 1.2 2020/02/26 12:28:02 micha Exp $

DISTNAME=	eureka-127-source
# The latest macOS patches were added after the release of 1.27 but
# unfortunately the archive name was not changed.
# Use version 1.27.1 for the package based on the updated source archive
PKGNAME=	${DISTNAME:S/-source/.1/:S/-1/-1./}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=eureka-editor/}

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/eureka-editor/
COMMENT=	Doom/Heretic/Hexen map editor
LICENSE=	gnu-gpl-v2

# Makefile declares "-std=c++03"
USE_LANGUAGES=	c++03
USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/eureka-1.27-source

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
