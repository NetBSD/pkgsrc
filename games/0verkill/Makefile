# $NetBSD: Makefile,v 1.8 2010/02/26 10:28:31 wiz Exp $

DISTNAME=	0verkill-0.16
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://artax.karlin.mff.cuni.cz/~brain/0verkill/release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://artax.karlin.mff.cuni.cz/~brain/0verkill/
COMMENT=	0verkill is bloody 2D action deathmatch-like game in ASCII-ART

PKG_DESTDIR_SUPPORT=	user-destdir

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
	cd ${WRKSRC} && ${INSTALL_PROGRAM} 0verkill ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && for f in avi bot editor server test_server; do \
		${INSTALL_PROGRAM} $$f ${DESTDIR}${PREFIX}/bin/0verkill-$$f; \
	done
	${INSTALL_DATA} ${WRKSRC}/data/* ${DESTDIR}${PREFIX}/share/0verkill/data
	${INSTALL_DATA} ${WRKSRC}/grx/* ${DESTDIR}${PREFIX}/share/0verkill/grx
	cd ${WRKSRC}/doc && ${INSTALL_DATA} AUTHORS README.html avi.txt \
		bot.txt doc.html ${DESTDIR}${PREFIX}/share/doc/0verkill

.include "../../mk/bsd.pkg.mk"
