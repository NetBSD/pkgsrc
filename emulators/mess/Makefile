# $NetBSD: Makefile,v 1.9 2012/03/03 00:14:25 wiz Exp $
#

DISTNAME=		mess0144s
PKGNAME=		${DISTNAME:S/0/-0./:S/s$//}
PKGREVISION=		3
MASTER_SITES=		http://www.mess.org/_media/downloads:
DISTFILES=		${DISTNAME:S/mess/mame/}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}

COMMENT=		Multi Emulator Super System

CONFLICTS=		xmess-[0-9]* sdlmess-[0-9]*

DOCDIR=			share/doc/mess
SHAREDIR=		share/mess
INSTALLATION_DIRS=	bin ${DOCDIR}/sysinfo ${SHAREDIR}/artwork \
			${SHAREDIR}/hash

# to build mess, not mame
MAKE_FLAGS=		TARGET=mess

post-build:
	cd ${WRKSRC} && ${MKDIR} sysinfo && ./dat2html

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
	${INSTALL_DATA} ${WRKSRC}/sysinfo.htm ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/sysinfo/* \
		${DESTDIR}${PREFIX}/${DOCDIR}/sysinfo

.include "../../emulators/mame/Makefile.common"
