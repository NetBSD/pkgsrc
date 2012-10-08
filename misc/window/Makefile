# $NetBSD: Makefile,v 1.3 2012/10/08 09:57:41 asau Exp $

DISTNAME=	window-20120215
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Windowing environment for ASCII terminals
LICENSE=	modified-bsd

# The current distfile relies on the NetBSD make system and does not use any
# kind of autoconfiguration.  This is done purely for simplicity reasons but
# is why this package is restricted to NetBSD.  If anyone is willing to
# improve the distfile to be more portable (e.g. by adding autoconf support),
# we can remove this limitation.
ONLY_FOR_PLATFORM=	NetBSD-[5-9]*-*

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/window ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/window.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
