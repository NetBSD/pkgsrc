# $NetBSD: Makefile,v 1.7 2012/10/31 11:19:21 asau Exp $
#

DISTNAME=		palmpower-1.0.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_BACKUP}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.palmblvd.com/software/pc/PilotDis-2000-05-04-palm-pc.html
COMMENT=		Assembler, disassembler and other tools for PalmOS binaries

CPPFLAGS+=		-Dunix

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-build:
	cd ${WRKSRC}/utils &&						\
	${CC} ${CFLAGS} -o splitprc splitprc.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/pila/pila ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/pilotdis/pilotdis ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/utils/splitprc ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/pilotdis.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
