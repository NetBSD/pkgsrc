# $NetBSD: Makefile,v 1.10 2004/10/03 00:14:47 tv Exp $
#

DISTNAME=	tuxmath-2001.09.07-0102
PKGNAME=	tuxmath-20010907
PKGREVISION=			4
CATEGORIES=	games math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxmath/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.newbreedsoftware.com/tuxmath/
COMMENT=	Educational math arcade game

WRKSRC=		${WRKDIR}/tuxmath
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
NO_CONFIGURE=	# defined

pre-install:
	${FIND} ${WRKSRC} -name CVS -type d  -print | ${XARGS} ${RM} -rf
	${RM} -rf ${WRKSRC}/data/images/.xvpics
	${RM} -rf ${WRKSRC}/data/images/status/.xvpics

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tuxmath
	${INSTALL_DATA} ${WRKSRC}/docs/README.txt ${PREFIX}/share/doc/tuxmath/

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
