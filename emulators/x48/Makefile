# $NetBSD: Makefile,v 1.3 2003/03/29 12:40:52 jmmv Exp $
#

DISTNAME=	x48_041
PKGNAME=	x48-0.4.1
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	emulators
MASTER_SITES=	http://home.earthlink.net/~rmmlgetz/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://home.earthlink.net/~rmmlgetz/
COMMENT=	HP48 emulator

USE_IMAKE=	YES

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
