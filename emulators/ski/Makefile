#	$NetBSD: Makefile,v 1.1.1.1 2005/10/05 11:58:50 skrll Exp $

DISTNAME=		ski-0.9.81-l6-i686
CATEGORIES=		emulators
MASTER_SITES=		# empty

MAINTAINER=		skrll@NetBSD.org
HOMEPAGE=		http://www.hpl.hp.com/research/linux/ski/
COMMENT=		The Hewlett-Packard IA-64 instruction set simulator for Linux/x86

RESTRICTED=		"Modification or Redistribution not permitted"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

ONLY_FOR_PLATFORM=	*-*-i386

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
DEPENDS+=		suse_x11>=6.1:../../emulators/${SUSE_DIR_PREFIX}_x11
.endif

WRKSRC=			${WRKDIR}
INTERACTIVE_STAGE=	fetch extract
CHECK_SHLIBS=		NO
NO_BUILD=		YES

DOWNLOAD=		http://www.hpl.hp.com/research/linux/ski/download.php

_FETCH_MESSAGE= \
	    ${ECHO} "==============================================================="; \
	    ${ECHO} "  Due to licensing restrictions, "; \
	    ${ECHO} "  the HP Ski IA-64 emulator for Linux 2.x (i686) must be fetched"; \
	    ${ECHO} "  into ${DISTDIR} from"; \
	    ${ECHO} "  ${DOWNLOAD}"; \
	    ${ECHO} "==============================================================="

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/nue/usr/bin/*ski* ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/nue/usr/man/man1/*ski*.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/nue/usr/X11R6/lib/X11/app-defaults/XSki ${PREFIX}/lib/X11/app-defaults/XSki

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
