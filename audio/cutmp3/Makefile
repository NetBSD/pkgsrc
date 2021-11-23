# $NetBSD: Makefile,v 1.1 2021/11/23 10:59:40 nia Exp $

DISTNAME=	cutmp3-3.0.1
CATEGORIES=	audio
MASTER_SITES=	https://www.puchalla-online.de/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.puchalla-online.de/cutmp3.html
COMMENT=	Command line editor for cutting MP3s without quality loss
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/cutmp3

pre-build:
	cp ${FILESDIR}/Makefile ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cutmp3 ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cutmp3.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/Changelog ${DESTDIR}${PREFIX}/share/cutmp3
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/cutmp3
	${INSTALL_DATA} ${WRKSRC}/USAGE ${DESTDIR}${PREFIX}/share/cutmp3
	${INSTALL_DATA} ${WRKSRC}/exitcodes ${DESTDIR}${PREFIX}/share/cutmp3

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
