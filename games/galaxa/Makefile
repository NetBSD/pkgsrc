# $NetBSD: Makefile,v 1.5 2000/01/07 19:02:07 hubertf Exp $
#

DISTNAME=	galaxa.0.1
PKGNAME=	galaxa-0.1
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/galaxa/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.newbreedsoftware.com/galaxa/

WRKSRC=		${WRKDIR}/galaxa
MAKEFILE=	makefile
USE_X11BASE=	yes

pre-install:
	${MKDIR} ${PREFIX}/share/doc/galaxa
	${CP} ${WRKSRC}/README.txt ${PREFIX}/share/doc/galaxa

.include "../../mk/bsd.pkg.mk"
