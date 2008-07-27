# $NetBSD: Makefile,v 1.12 2008/07/27 22:35:17 dholland Exp $

DISTNAME=	lmarbles-1.0.7
PKGREVISION=	6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	Atomix-like puzzle

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

PROFILE_DIR=		${VARBASE}/games
DOC_DIR=		${PREFIX}/share/doc/${PKGBASE}
EXAMPLES_DIR=		${PREFIX}/share/examples/${PKGBASE}

CONFIGURE_ARGS+=	--localstatedir=${PROFILE_DIR}

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-configure
SUBST_FILES.path=	src/lmarbles.6
SUBST_SED.path+=	-e 's;/var/lib/games;${PROFILE_DIR};g'
SUBST_SED.path+=	-e 's;/usr/share/doc/marbles;${DOC_DIR};g'

SETGIDGAME=		yes
SPECIAL_PERMS=		bin/lmarbles ${SETGID_GAMES_PERMS}
REQD_DIRS_PERMS+=	${PROFILE_DIR} ${GAMEOWN} ${GAMEGRP} ${GAMEDIRMODE}
REQD_FILES_PERMS+=	${EXAMPLES_DIR}/lmarbles.prfs ${PROFILE_DIR}/lmarbles.prfs \
			${GAMEOWN} ${GAMEGRP} ${GAMEDATAMODE}

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		GAMEDATAMODE
BUILD_DEFS+=		GAMEMODE

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} != "little"
CONFIGURE_ARGS+=	--enable-ascii
.endif

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOC_DIR}
	(cd ${WRKSRC}/src/manual; for d in *; do			\
		${INSTALL_DATA} $${d} ${DESTDIR}${DOC_DIR}/$${d};	\
	done)
	${INSTALL_DATA_DIR} ${DESTDIR}${EXAMPLES_DIR}
	${INSTALL_DATA} ${WRKSRC}/src/empty.prfs			\
		${DESTDIR}${EXAMPLES_DIR}/lmarbles.prfs

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
