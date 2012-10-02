# $NetBSD: Makefile,v 1.14 2012/10/02 17:10:59 tron Exp $
#

DISTNAME=		mame0146s
PKGNAME=		${DISTNAME:S/0/-0./:S/s$//}
PKGREVISION=		4
MASTER_SITES=		http://mamedev.org/downloader.php?file=releases/

COMMENT=		Multiple Arcade Machine Emulator

CONFLICTS=		xmame-[0-9]* sdlmame-[0-9]*

DOCDIR=			share/doc/mame
INSTALLATION_DIRS=	bin ${DOCDIR} ${PKGMANDIR}/man1 ${PKGMANDIR}/man6

# mame source is double-zipped
post-extract:
	cd ${WRKDIR} && ${.CURDIR}/../../mk/extract/extract mame.zip
	rm ${WRKDIR}/mame.zip

# not installed, because not found necessary so far:
# regrep, split, src2html, srcclean, testkeys
do-install:
	set -e; \
	for prg in chdman jedutil ldresample ldverify mame romcmp unidasm; \
	do \
		${INSTALL_PROGRAM} ${WRKSRC}/"$$prg" ${DESTDIR}${PREFIX}/bin; \
	done
	set -e; \
	for doc in config.txt license.txt mame.txt; do \
		${INSTALL_DATA} ${WRKSRC}/docs/"$$doc" ${DESTDIR}${PREFIX}/${DOCDIR}; \
	done
# skipped: ldplayer man page exists, but no binary?
# skipped: testkeys, binary not installed
	set -e; \
	for man in chdman.1 jedutil.1 ldverify.1 romcmp.1; \
	do \
		${INSTALL_DATA} ${WRKSRC}/src/osd/sdl/man/"$$man" ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1; \
	done
	${INSTALL_DATA} ${WRKSRC}/src/osd/sdl/man/mame.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6; \

.include "Makefile.common"
