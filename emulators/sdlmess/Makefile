# $NetBSD: Makefile,v 1.3 2009/06/06 21:42:45 wiz Exp $
#

DISTNAME=		sdlmess0131
PKGNAME=		sdlmess-0.131

COMMENT=		Multi Emulator Super System, SDL port

CONFLICTS=		xmess-[0-9]*

MAKE_FILE=		makefile

PATCHDIR=		${.CURDIR}/../../emulators/sdlmame/patches

DOCDIR=			share/doc/mess
SHAREDIR=		share/mess
INSTALLATION_DIRS=	bin ${DOCDIR}/sysinfo ${SHAREDIR}/artwork \
			${SHAREDIR}/hash

pre-patch:
	cd ${WRKSRC} && mv makefile.sdl makefile

post-build:
	cd ${WRKSRC} && ./dat2html

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/castool ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/imgtool ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mess ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/artwork/* \
		${DESTDIR}${PREFIX}/${SHAREDIR}/artwork
	${INSTALL_DATA} ${WRKSRC}/hash/* \
		${DESTDIR}${PREFIX}/${SHAREDIR}/hash
	${INSTALL_DATA} ${WRKSRC}/sysinfo.htm ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/sysinfo/* \
		${DESTDIR}${PREFIX}/${DOCDIR}/sysinfo

.include "../../emulators/sdlmame/Makefile.common"
