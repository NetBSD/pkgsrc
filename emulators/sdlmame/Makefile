# $NetBSD: Makefile,v 1.7 2009/09/20 10:03:58 wiz Exp $
#

# Don't update to 0.XXXuN, those are development snapshots.
DISTNAME=		sdlmame0134
PKGNAME=		${DISTNAME:S/0/-0./}

COMMENT=		Multiple Arcade Machine Emulator, SDL port

CONFLICTS=		xmame-[0-9]*

MAKE_FILE=		makefile

DOCDIR=			share/doc/sdlmame
INSTALLATION_DIRS=	bin ${DOCDIR}

do-install:
	set -e; \
	for prg in chdman jedutil mame romcmp; \
	do \
		${INSTALL_PROGRAM} ${WRKSRC}/"$$prg" ${DESTDIR}${PREFIX}/bin; \
	done
	${INSTALL_DATA} ${WRKSRC}/SDLMAME.txt ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/license.txt ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/mame.txt ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/windows.txt ${DESTDIR}${PREFIX}/${DOCDIR}

.include "Makefile.common"
