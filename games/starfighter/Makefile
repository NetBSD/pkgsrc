# $NetBSD: Makefile,v 1.1.1.1 2004/10/15 05:36:43 xtraeme Exp $
#

DISTNAME=	starfighter-1.1-1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/xtraeme/
DISTFILES=	${DISTNAME}.tar.gz starfighter-1.0-1.music.zip

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.parallelrealities.co.uk/starfighter.php
COMMENT=	Old school 2D shoot them up

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_LANGUAGES+=	c++
USE_X11=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/-1$//}

MAKEFILE=	makefile

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/starfighter/music
	cd ${WRKDIR}/music && ${PAX} -rwppm . \
		${PREFIX}/share/starfighter/music 

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
