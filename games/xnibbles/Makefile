# $NetBSD: Makefile,v 1.20 2008/01/19 09:16:23 wiz Exp $
#

DISTNAME=		xnibbles-1.0BETA4
PKGNAME=		xnibbles-1.0b4
PKGREVISION=		2
CATEGORIES=		games x11
MASTER_SITES=		http://www.tjhsst.edu/xnibbles/

MAINTAINER=		pkgsrc-users@NetBSD.org
# HOMEPAGE=		http://www.tjhsst.edu/xnibbles/
# not maintained since 1999, rewritten into gnibbles
COMMENT=		Winding snakes game for X11

WRKSRC=			${WRKDIR}/xnibbles
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

SUBST_CLASSES+=		audio
SUBST_STAGE.audio=	pre-build
SUBST_MESSAGE.audio=	Adjusting path to audio device
SUBST_FILES.audio=	Makefile
SUBST_SED.audio=	-e "s|/dev/dsp|${DEVOSSAUDIO}|"

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
