#	$NetBSD: Makefile,v 1.2 2012/10/03 12:55:17 asau Exp $

DISTNAME=		ski-0.9.81-l6-i686
PKGNAME=		ski-0.9.81.6
CATEGORIES=		emulators
MASTER_SITES=		# empty

MAINTAINER=		skrll@NetBSD.org
HOMEPAGE=		http://www.hpl.hp.com/research/linux/ski/
COMMENT=		The Hewlett-Packard IA-64 instruction set simulator for Linux/x86

RESTRICTED=		Modification or Redistribution not permitted
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	x11

WRKSRC=			${WRKDIR}
INTERACTIVE_STAGE=	fetch
BUILD_DIRS=		# none

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 lib/X11/app-defaults

DOWNLOAD=		http://www.hpl.hp.com/research/linux/ski/download.php

FETCH_MESSAGE=								\
	"Due to licensing restrictions, the HP Ski IA-64 emulator for"	\
	"Linux 2.x (i686) must be fetched into:"			\
	"    ${DISTDIR}"						\
	"from:"								\
	"    ${DOWNLOAD}"

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/nue/usr/bin/*ski* ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/nue/usr/man/man1/*ski*.1		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKDIR}/nue/usr/X11R6/lib/X11/app-defaults/XSki \
		${DESTDIR}${PREFIX}/lib/X11/app-defaults/XSki

.include "../../mk/bsd.pkg.mk"
