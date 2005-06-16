# $NetBSD: Makefile,v 1.4 2005/06/16 06:57:52 jlam Exp $
#

DISTNAME=	0verkill-0.15
CATEGORIES=	games
MASTER_SITES=	http://artax.karlin.mff.cuni.cz/~brain/0verkill/release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://artax.karlin.mff.cuni.cz/~brain/0verkill/
COMMENT=	0verkill is bloody 2D action deathmatch-like game in ASCII-ART

HAS_CONFIGURE=	YES

INSTALLATION_DIRS=	bin

post-patch:
	${SED} "s|@PREFIX@|${PREFIX}|g" ${WRKSRC}/cfg.h > ${WRKSRC}/cfg.h.done
	${MV} ${WRKSRC}/cfg.h.done ${WRKSRC}/cfg.h
	${SED} "s|grx/|${PREFIX}/share/0verkill/grx/|g" ${WRKSRC}/data/sprites.dat \
		> ${WRKSRC}/data/sprites.dat.done
	${MV} ${WRKSRC}/data/sprites.dat.done ${WRKSRC}/data/sprites.dat

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/0verkill \
		${PREFIX}/share/doc/0verkill ${PREFIX}/share/0verkill/data \
		${PREFIX}/share/0verkill/grx
	cd ${WRKSRC} && ${INSTALL_PROGRAM} 0verkill ${PREFIX}/bin
	cd ${WRKSRC} && for f in avi bot editor server test_server; do \
		${INSTALL_PROGRAM} $$f ${PREFIX}/bin/0verkill-$$f; \
	done
	cd ${WRKSRC}/data && ${INSTALL_DATA} banner.dat dynamic.dat room.dat \
		sprites.dat ${PREFIX}/share/0verkill/data
	${INSTALL_DATA} ${WRKSRC}/grx/* ${PREFIX}/share/0verkill/grx
	cd ${WRKSRC}/doc && ${INSTALL_DATA} AUTHORS README.html avi.txt \
		bot.txt doc.html ${PREFIX}/share/doc/0verkill

.include "../../mk/bsd.pkg.mk"
