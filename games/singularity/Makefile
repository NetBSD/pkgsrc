# $NetBSD: Makefile,v 1.1.1.1 2007/09/04 07:36:21 wiz Exp $
#

DISTNAME=		singularity_0.26a
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		games
MASTER_SITES=		http://www.emhsoft.com/singularity/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.emhsoft.com/singularity/
COMMENT=		Endgame: Singularity game

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin share/doc/singularity \
			share/singularity/code \
			share/singularity/data/music-src \
			share/singularity/music

do-build:
	${ECHO} "#!/bin/sh" > ${WRKSRC}/singularity
	${ECHO} "cd ${PREFIX}/share/singularity/code" >> ${WRKSRC}/singularity
	${ECHO} "${PYTHONBIN} singularity.py" >> ${WRKSRC}/singularity

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/singularity ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/code/*.py ${PREFIX}/share/singularity/code
	${INSTALL_DATA} ${WRKSRC}/data/*.* ${PREFIX}/share/singularity/data
	${INSTALL_DATA} ${WRKSRC}/data/music-src/* \
		${PREFIX}/share/singularity/data/music-src
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/singularity

.include "../../devel/py-game/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
