# $NetBSD: Makefile,v 1.28 2023/12/22 19:24:26 zafer Exp $
#

DISTNAME=		xnibbles-1.0BETA4
PKGNAME=		xnibbles-1.0b4
PKGREVISION=		4
CATEGORIES=		games x11
MASTER_SITES=		#

MAINTAINER=		pkgsrc-users@NetBSD.org
# HOMEPAGE=		http://www.tjhsst.edu/xnibbles/
# not maintained since 1999, rewritten into gnibbles
COMMENT=		Winding snakes game for X11

WRKSRC=			${WRKDIR}/xnibbles
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

# Fails with C++14 default language.
FORCE_CXX_STD=		c++03

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none" && ${DEVOSSAUDIO} != /dev/dsp
SUBST_CLASSES+=		audio
SUBST_STAGE.audio=	pre-build
SUBST_MESSAGE.audio=	Adjusting path to audio device
SUBST_FILES.audio=	Makefile
SUBST_SED.audio=	-e "s|/dev/dsp|${DEVOSSAUDIO}|"
.endif

# boni.c: In member function 'void boni::addBonus(char, int)':
# boni.c:65:21: error: array subscript has type 'char' [-Werror=char-subscripts]
#    } while (objects[x][y] != 'a' || objects[x + 1][y] != 'a' || objects[x][y + 1] != 'a' || objects[x + 1][y + 1] != 'a');
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
