# $NetBSD: Makefile,v 1.17.2.1 2012/10/03 12:07:38 spz Exp $
#

DISTNAME=		mess0146s
PKGNAME=		${DISTNAME:S/0/-0./:S/s$//}
PKGREVISION=		4
# original master site on cookie/javascript/whatever site
MASTER_SITES=		# http://www.mess.org/_media/downloads:

COMMENT=		Multi Emulator Super System

CONFLICTS=		xmess-[0-9]* sdlmess-[0-9]*

DOCDIR=			share/doc/mess
SHAREDIR=		share/mess
INSTALLATION_DIRS=	bin ${DOCDIR} ${SHAREDIR}/artwork ${SHAREDIR}/hash

INTERACTIVE_STAGE=	fetch
FETCH_MESSAGE=		"Distfile is on sendspace.com, please download manually." \
			"Follow the link for \"MESS "${DISTNAME:S/mess//:S/s//:S/0/0./}" Source\" on http://www.mess.org/downloads"

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
	for doc in credits.htm faq.htm howto.htm imgtool.txt license.txt; do \
		${INSTALL_DATA} ${WRKSRC}/docs/"$$doc" ${DESTDIR}${PREFIX}/${DOCDIR}; \
	done
	${INSTALL_DATA} ${WRKSRC}/artwork/* \
		${DESTDIR}${PREFIX}/${SHAREDIR}/artwork
	${INSTALL_DATA} ${WRKSRC}/hash/* \
		${DESTDIR}${PREFIX}/${SHAREDIR}/hash

.include "../../emulators/mame/Makefile.common"
