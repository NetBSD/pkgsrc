# $NetBSD: Makefile,v 1.3 2008/03/04 06:59:06 jlam Exp $
#

DISTNAME=		singularity_0.26a
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		games
MASTER_SITES=		http://www.emhsoft.com/singularity/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.emhsoft.com/singularity/
COMMENT=		Endgame: Singularity game

PKG_DESTDIR_SUPPORT=	user-destdir

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
	${INSTALL_SCRIPT} ${WRKSRC}/singularity ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/code/*.py \
		${DESTDIR}${PREFIX}/share/singularity/code
	${INSTALL_DATA} ${WRKSRC}/data/*.* \
		${DESTDIR}${PREFIX}/share/singularity/data
	${INSTALL_DATA} ${WRKSRC}/data/music-src/* \
		${DESTDIR}${PREFIX}/share/singularity/data/music-src
	${INSTALL_DATA} ${WRKSRC}/README.txt \
		${DESTDIR}${PREFIX}/share/doc/singularity

.include "../../devel/py-game/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
