# $NetBSD: Makefile,v 1.4 2003/12/08 14:41:40 wiz Exp $
#

DISTNAME=	tuxmath-2001.09.07-0102
PKGNAME=	tuxmath-20010907
PKGREVISION=			2
WRKSRC=		${WRKDIR}/tuxmath
CATEGORIES=	games math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxmath/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.newbreedsoftware.com/tuxmath/
COMMENT=	Educational math arcade game

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
NO_CONFIGURE=	# defined

pre-install:
	${FIND} ${WRKSRC} -name CVS -type d  | ${XARGS} ${RM} -rf
	${RM} -rf ${WRKSRC}/data/images/.xvpics
	${RM} -rf ${WRKSRC}/data/images/status/.xvpics

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tuxmath
	${INSTALL_DATA} ${WRKSRC}/docs/README.txt ${PREFIX}/share/doc/tuxmath/

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../graphics/SDL_image/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
