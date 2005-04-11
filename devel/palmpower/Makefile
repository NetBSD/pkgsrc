# $NetBSD: Makefile,v 1.2 2005/04/11 21:45:36 tv Exp $
#

DISTNAME=		palmpower-1.0.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_BACKUP}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.palmblvd.com/software/pc/PilotDis-2000-05-04-palm-pc.html
COMMENT=		Assembler, disassembler and other tools for PalmOS binaries

CPPFLAGS+=		-Dunix

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

post-build:
	cd ${WRKSRC}/utils &&						\
	${CC} ${CFLAGS} -o splitprc splitprc.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/pila/pila ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/pilotdis/pilotdis ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/utils/splitprc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/pilotdis.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
