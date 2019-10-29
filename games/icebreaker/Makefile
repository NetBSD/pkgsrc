# $NetBSD: Makefile,v 1.34 2019/10/29 18:04:44 nia Exp $

DISTNAME=	icebreaker-1.9.8
CATEGORIES=	games
MASTER_SITES=	https://mattdm.org/icebreaker/1.9.x/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mattdm.org/icebreaker/
COMMENT=	Action-puzzle game involving bouncing penguins
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	icoutils-[0-9]*:../../graphics/icoutils

USE_TOOLS+=	gmake

BUILD_DEFS+=	VARBASE

MAKE_ENV+=	mandir="${PREFIX}/man"
MAKE_ENV+=	highscoredir="${VARBASE}/games"
MAKE_ENV+=	prefix=${PREFIX}

USE_GAMESGROUP=	yes
SPECIAL_PERMS=	bin/icebreaker ${SETGID_GAMES_PERMS}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/doc/icebreaker
INSTALLATION_DIRS+=	share/icebreaker
INSTALLATION_DIRS+=	share/icons/hicolor/32x32/apps
INSTALLATION_DIRS+=	share/icons/hicolor/48x48/apps

post-build:
	cd ${WRKSRC} && ${PREFIX}/bin/icotool -i 1 -x -o 32.png ${WRKSRC}/icebreaker_32.ico
	cd ${WRKSRC} && ${PREFIX}/bin/icotool -i 2 -x -o 48.png ${WRKSRC}/icebreaker_32.ico

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} *.ibt *.wav *.bmp \
		${DESTDIR}${PREFIX}/share/icebreaker
	${INSTALL_PROGRAM} ${WRKSRC}/icebreaker ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/icebreaker.6 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6
	${INSTALL_DATA} ${WRKSRC}/icebreaker.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/32.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/32x32/apps/icebreaker.png
	${INSTALL_DATA} ${WRKSRC}/48.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/48x48/apps/icebreaker.png
.for file in ChangeLog README LICENSE
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/share/doc/icebreaker
.endfor

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
