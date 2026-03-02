# $NetBSD: Makefile,v 1.6.66.1 2026/03/02 23:00:24 buhrow Exp $

DISTNAME=	window-20260302
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Windowing environment for ASCII terminals
LICENSE=	modified-bsd

USE_BSD_MAKEFILE=	yes
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/window ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/window.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
