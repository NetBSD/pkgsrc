# $NetBSD: Makefile,v 1.2 2001/04/27 14:59:42 wiz Exp $
#

DISTNAME=	x48_041
PKGNAME=	x48-0.4.1
CATEGORIES=	emulators
MASTER_SITES=	http://home.earthlink.net/~rmmlgetz/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://home.earthlink.net/~rmmlgetz/
COMMENT=	HP48 emulator

USE_IMAKE=	YES

WRKSRC=		${WRKDIR}/${PKGNAME}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/x48 \
		${PREFIX}/share/doc/x48/romdump
	cd ${WRKSRC}/doc && \
		${INSTALL_MAN} CARDS.doc INSTALLING ROMDump.doc \
			${PREFIX}/share/doc/x48
	cd ${WRKSRC}/romdump && \
		${INSTALL_MAN} README ${PREFIX}/share/doc/x48/romdump && \
		${INSTALL_DATA} ROMDump ROMDump.s \
			${PREFIX}/share/doc/x48/romdump

.include "../../mk/bsd.pkg.mk"
