# $NetBSD: Makefile,v 1.3 1998/04/15 10:38:07 agc Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/11/20 08:18:40 tg Exp
#

DISTNAME=	bzip2-0.1pl2
PKGNAME=	bzip2-0.1p2
CATEGORIES=	archivers
MASTER_SITES=	http://www.muraroa.demon.co.uk/

MAINTAINER=	ports@FreeBSD.org

MAN1=		bzip2.1 bunzip2.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bzip2 ${PREFIX}/bin
	ln -sf ${PREFIX}/bin/bzip2 ${PREFIX}/bin/bunzip2
	${INSTALL_PROGRAM} ${WRKSRC}/bzip2recover ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bzip2.1 ${PREFIX}/man/man1
	ln ${PREFIX}/man/man1/bzip2.1 ${PREFIX}/man/man1/bunzip2.1

.include "../../mk/bsd.pkg.mk"
