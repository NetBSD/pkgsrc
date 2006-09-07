# $NetBSD: Makefile,v 1.5 2006/09/07 05:39:37 adam Exp $

DISTNAME=	0verkill-0.16
CATEGORIES=	games
MASTER_SITES=	http://artax.karlin.mff.cuni.cz/~brain/0verkill/release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://artax.karlin.mff.cuni.cz/~brain/0verkill/
COMMENT=	0verkill is bloody 2D action deathmatch-like game in ASCII-ART

HAS_CONFIGURE=		yes

INSTALLATION_DIRS=	bin share/0verkill share/doc/0verkill
INSTALLATION_DIRS+=	share/0verkill/data share/0verkill/grx

SUBST_CLASSES+=		grx
SUBST_STAGE.grx=	post-patch
SUBST_MESSAGE.grx=	Fix game data paths
SUBST_FILES.grx=	data/sprites.dat data/level1.sp data/level2.sp
SUBST_SED.grx=		-e "s|grx/|${PREFIX}/share/0verkill/grx/|g"

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_MESSAGE.prefix=	Fix game configuration path prefix
SUBST_FILES.prefix=	cfg.h
SUBST_SED.prefix=	-e "s|@PREFIX@|${PREFIX}|g"

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} 0verkill ${PREFIX}/bin
	cd ${WRKSRC} && for f in avi bot editor server test_server; do \
		${INSTALL_PROGRAM} $$f ${PREFIX}/bin/0verkill-$$f; \
	done
	${INSTALL_DATA} ${WRKSRC}/data/* ${PREFIX}/share/0verkill/data
	${INSTALL_DATA} ${WRKSRC}/grx/* ${PREFIX}/share/0verkill/grx
	cd ${WRKSRC}/doc && ${INSTALL_DATA} AUTHORS README.html avi.txt \
		bot.txt doc.html ${PREFIX}/share/doc/0verkill

.include "../../mk/bsd.pkg.mk"
