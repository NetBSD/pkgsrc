# $NetBSD: Makefile,v 1.11 2012/05/31 16:52:27 shattered Exp $
#

DISTNAME=		mess0145s
PKGNAME=		${DISTNAME:S/0/-0./:S/s$//}
PKGREVISION=		1
MASTER_SITES=		http://www.mess.org/_media/downloads:

COMMENT=		Multi Emulator Super System

CONFLICTS=		xmess-[0-9]* sdlmess-[0-9]*

DOCDIR=			share/doc/mess
SHAREDIR=		share/mess
INSTALLATION_DIRS=	bin ${DOCDIR} ${SHAREDIR}/artwork ${SHAREDIR}/hash

# to build mess, not mame
MAKE_FLAGS=		TARGET=mess

do-install:
# ignored: messtest
# remaining tools are installed with mame
	set -e; \
	for prg in castool chdman floptool imgtool mess unidasm; \
	do \
		${INSTALL_PROGRAM} ${WRKSRC}/"$$prg" ${DESTDIR}${PREFIX}/bin; \
	done
	set -e; \
	for doc in credits.htm faq.htm howto.htm imgtool.txt license.txt; do \
		${INSTALL_DATA} ${WRKSRC}/docs/"$$doc" ${DESTDIR}${PREFIX}/${DOCDIR}; \
	done
	${INSTALL_DATA} ${WRKSRC}/artwork/* \
		${DESTDIR}${PREFIX}/${SHAREDIR}/artwork
	${INSTALL_DATA} ${WRKSRC}/hash/* \
		${DESTDIR}${PREFIX}/${SHAREDIR}/hash

.include "../../emulators/mame/Makefile.common"
