# $NetBSD: Makefile,v 1.4 1999/01/30 23:18:47 agc Exp $
#

DISTNAME=	galaxa.0.1
PKGNAME=	galaxa-0.1
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/galaxa/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.sonic.net/~nbs/unix/x/galaxa/

WRKSRC=		${WRKDIR}/galaxa
MAKEFILE=	makefile
USE_X11BASE=	yes

pre-install:
	${MKDIR} ${PREFIX}/share/doc/galaxa
	${CP} ${WRKSRC}/README.txt ${PREFIX}/share/doc/galaxa

.include "../../mk/bsd.pkg.mk"
