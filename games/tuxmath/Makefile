# $NetBSD: Makefile,v 1.25 2012/01/28 11:00:56 wiz Exp $
#

DISTNAME=	tuxmath-2001.09.07-0102
PKGNAME=	tuxmath-20010907
PKGREVISION=	15
CATEGORIES=	games math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxmath/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.newbreedsoftware.com/tuxmath/
COMMENT=	Educational math arcade game

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/tuxmath
USE_TOOLS+=	gmake
NO_CONFIGURE=	yes

INSTALLATION_DIRS+=	bin share/doc/tuxmath

pre-install:
	${FIND} ${WRKSRC} -name CVS -type d  -print | ${XARGS} ${RM} -rf
	${RM} -rf ${WRKSRC}/data/images/.xvpics
	${RM} -rf ${WRKSRC}/data/images/status/.xvpics

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/README.txt ${DESTDIR}${PREFIX}/share/doc/tuxmath/

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
