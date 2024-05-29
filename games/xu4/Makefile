# $NetBSD: Makefile,v 1.16 2024/05/29 16:32:45 adam Exp $
#

DISTNAME=	xu4-1.0beta3
PKGREVISION=	12
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xu4/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xu4.sourceforge.net/
COMMENT=	Remake of Ultima IV
LICENSE=	gnu-gpl-v2

DEPENDS+=	timidity-[0-9]*:../../audio/timidity

WRKSRC=		${WRKDIR}/u4
CONFIGURE_DIRS=	src
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	share/doc/xu4

SUBST_CLASSES+=		prefix
SUBST_SED.prefix=	-e "s,/usr/local,${PREFIX},"
SUBST_FILES.prefix=	src/u4file.cpp README
SUBST_STAGE.prefix=	pre-build
SUBST_MESSAGE.prefix=	Fixing path to installed files.

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/xu4

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
