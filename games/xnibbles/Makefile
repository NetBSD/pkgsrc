# $NetBSD: Makefile,v 1.16 2006/03/09 21:04:44 jlam Exp $
#

DISTNAME=		xnibbles-1.0BETA4
PKGNAME=		xnibbles-1.0b4
PKGREVISION=		2
CATEGORIES=		games x11
MASTER_SITES=		http://www.tjhsst.edu/xnibbles/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.tjhsst.edu/xnibbles/
COMMENT=		Winding snakes game for X11

WRKSRC=			${WRKDIR}/xnibbles
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

SUBST_CLASSES+=		audio
SUBST_STAGE.audio=	pre-build
SUBST_MESSAGE.audio=	Adjusting path to audio device
SUBST_FILES.audio=	Makefile
SUBST_SED.audio=	-e "s|/dev/dsp|${DEVOSSAUDIO}|"

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
