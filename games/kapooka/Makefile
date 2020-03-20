# $NetBSD: Makefile,v 1.23 2020/03/20 11:57:42 nia Exp $
#

DISTNAME=		kapooka_0.2
PKGNAME=		${DISTNAME:S/_/-/}
PKGREVISION=		13
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kapooka/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kapooka.sourceforge.net/
COMMENT=		Puzzle game

WRKSRC=			${WRKDIR}/kapooka
USE_TOOLS+=		gmake

SUBST_CLASSES+=		kapooka
SUBST_STAGE.kapooka=	pre-build
SUBST_MESSAGE.kapooka=	Fixing path to data files.
SUBST_FILES.kapooka=	main.h objects.c
SUBST_SED.kapooka=	"s!data/!${PREFIX}/share/kapooka/!"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kapooka ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/kapooka
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/kapooka/interface
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/kapooka/levelDummy
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/kapooka/music
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/kapooka/sound
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/kapooka/sprites
	${INSTALL_DATA} ${WRKSRC}/data/level.dat \
		${DESTDIR}${PREFIX}/share/kapooka
	${INSTALL_DATA} ${WRKSRC}/data/interface/* \
		${DESTDIR}${PREFIX}/share/kapooka/interface
	${INSTALL_DATA} ${WRKSRC}/data/levelDummy/* \
		${DESTDIR}${PREFIX}/share/kapooka/levelDummy
	${INSTALL_DATA} ${WRKSRC}/data/music/* \
		${DESTDIR}${PREFIX}/share/kapooka/music
	${INSTALL_DATA} ${WRKSRC}/data/sound/* \
		${DESTDIR}${PREFIX}/share/kapooka/sound
	${INSTALL_DATA} ${WRKSRC}/data/sprites/*.png \
		${DESTDIR}${PREFIX}/share/kapooka/sprites

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/libmikmod/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
