# $NetBSD: Makefile,v 1.26 2022/06/30 11:18:26 nia Exp $

DISTNAME=		singularity-0.30c-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=		5
CATEGORIES=		games
MASTER_SITES=		http://endgame-singularity.googlecode.com/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.emhsoft.com/singularity/
COMMENT=		Endgame: Singularity game

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin share/doc/singularity
INSTALLATION_DIRS+=	share/singularity/code
INSTALLATION_DIRS+=	share/singularity/code/graphics
INSTALLATION_DIRS+=	share/singularity/code/screens
INSTALLATION_DIRS+=	share/singularity/data/fonts
INSTALLATION_DIRS+=	share/singularity/data/images
INSTALLATION_DIRS+=	share/singularity/data/sounds
INSTALLATION_DIRS+=	share/singularity/music

do-build:
	${ECHO} "#!/bin/sh" > ${WRKSRC}/singularity
	${ECHO} "cd ${PREFIX}/share/singularity" >> ${WRKSRC}/singularity
	${ECHO} "${PYTHONBIN} singularity.py" >> ${WRKSRC}/singularity

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/singularity ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/singularity.py ${DESTDIR}${PREFIX}/share/singularity
	${INSTALL_DATA} ${WRKSRC}/code/*.py \
		${DESTDIR}${PREFIX}/share/singularity/code
	${INSTALL_DATA} ${WRKSRC}/code/graphics/*.py \
		${DESTDIR}${PREFIX}/share/singularity/code/graphics
	${INSTALL_DATA} ${WRKSRC}/code/screens/*.py \
		${DESTDIR}${PREFIX}/share/singularity/code/screens
	${INSTALL_DATA} ${WRKSRC}/data/*.* \
		${DESTDIR}${PREFIX}/share/singularity/data
	${INSTALL_DATA} ${WRKSRC}/data/fonts/*.* \
		${DESTDIR}${PREFIX}/share/singularity/data/fonts
	${INSTALL_DATA} ${WRKSRC}/data/images/*.* \
		${DESTDIR}${PREFIX}/share/singularity/data/images
	${INSTALL_DATA} ${WRKSRC}/data/sounds/*.* \
		${DESTDIR}${PREFIX}/share/singularity/data/sounds
	${INSTALL_DATA} ${WRKSRC}/README.txt \
		${DESTDIR}${PREFIX}/share/doc/singularity

.include "../../devel/py-game/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
