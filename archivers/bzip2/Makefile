# $NetBSD: Makefile,v 1.9 1998/10/14 21:51:14 tron Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/11/20 08:18:40 tg Exp
#

DISTNAME=	bzip2-0.9.0b
CATEGORIES=	archivers
MASTER_SITES=	http://www.muraroa.demon.co.uk/ \
		http://www.digistar.com/bzip2/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.muraroa.demon.co.uk/

CONFLICTS=	bzip2-0.1p2

.if exists(/usr/bin/bzip2)
IGNORE=		"is part of your NetBSD distribution"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bzip2 ${PREFIX}/bin
	ln -f ${PREFIX}/bin/bzip2 ${PREFIX}/bin/bunzip2
	ln -f ${PREFIX}/bin/bzip2 ${PREFIX}/bin/bzcat
	${INSTALL_PROGRAM} ${WRKSRC}/bzip2recover ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bzip2.1 ${PREFIX}/man/man1
	ln -sf ${PREFIX}/man/man1/bzip2.1 ${PREFIX}/man/man1/bunzip2.1
	ln -sf ${PREFIX}/man/man1/bzip2.1 ${PREFIX}/man/man1/bzcat.1
	ln -sf ${PREFIX}/man/man1/bzip2.1 ${PREFIX}/man/man1/bzip2recover.1

.include "../../mk/bsd.pkg.mk"
