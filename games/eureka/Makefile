# $NetBSD: Makefile,v 1.1 2019/09/11 16:26:17 micha Exp $

DISTNAME=	eureka-124-source
PKGNAME=	${DISTNAME:S/-source//:S/-1/-1./}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=eureka-editor/}

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/eureka-editor/
COMMENT=	Doom/Heretic/Hexen map editor
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}-source

# DOOMWADDIR is intentionally shared with other Doom packages
DOOMWADDIR=	share/doom

# Modify internal search path to check ${PREFIX}/share hierarchy first
SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	do-configure
SUBST_MESSAGE.prefix=	Preparing main.cc file ...
SUBST_FILES.prefix=	src/main.cc
SUBST_SED.prefix=	-e 's,PKGSRC_PREFIX,${PREFIX},'

# Modify internal search path for DOOMWADDIR (if environment variable not set)
SUBST_CLASSES+=		dwd
SUBST_STAGE.dwd=	do-configure
SUBST_MESSAGE.dwd=	Preparing m_files.cc file ...
SUBST_FILES.dwd=	src/m_files.cc
SUBST_SED.dwd=		-e 's,PKGSRC_DOOMWADDIR,${PREFIX}/${DOOMWADDIR},'

# Can be used by FLTK for fl_open_uri() on X11
DEPENDS+=			xdg-utils>=1.1:../../misc/xdg-utils

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.3
.include "../../devel/zlib/buildlink3.mk"
# FLTK version 1.4 is supported too
.include "../../x11/fltk13/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
