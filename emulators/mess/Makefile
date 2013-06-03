# $NetBSD: Makefile,v 1.23 2013/06/03 10:04:55 wiz Exp $

DISTNAME=	mame0148s
PKGNAME=	${DISTNAME:S/mame0/mess-0./:S/s$//}
PKGREVISION=	2
MASTER_SITES=	http://mamedev.org/downloader.php?file=releases/

COMMENT=	Multi Emulator Super System

CONFLICTS=		xmess-[0-9]* sdlmess-[0-9]*

DOCDIR=			share/doc/mess
SHAREDIR=		share/mess
INSTALLATION_DIRS=	bin ${DOCDIR} ${SHAREDIR}/artwork ${SHAREDIR}/hash

# mame source is double-zipped
post-extract:
	cd ${WRKDIR} && ${.CURDIR}/../../mk/extract/extract mame.zip
	rm ${WRKDIR}/mame.zip

# to build mess, not mame
MAKE_FLAGS=		TARGET=mess

do-install:
# ignored: messtest
# remaining tools are installed with mame
	set -e; \
	for prg in castool floptool imgtool mess; \
	do \
		${INSTALL_PROGRAM} ${WRKSRC}/"$$prg" ${DESTDIR}${PREFIX}/bin; \
	done
	set -e; \
	for doc in imgtool.txt license.txt; do \
		${INSTALL_DATA} ${WRKSRC}/docs/"$$doc" ${DESTDIR}${PREFIX}/${DOCDIR}; \
	done
	${INSTALL_DATA} ${WRKSRC}/artwork/* \
		${DESTDIR}${PREFIX}/${SHAREDIR}/artwork
	${INSTALL_DATA} ${WRKSRC}/hash/* \
		${DESTDIR}${PREFIX}/${SHAREDIR}/hash

.include "../../emulators/mame/Makefile.common"
