# $NetBSD: Makefile,v 1.1 1998/07/24 12:17:36 frueauf Exp $
#

DISTNAME=	galaxa.0.1
PKGNAME=	galaxa-0.1
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/galaxa/

MAINTAINER=	root@garbled.net

WRKSRC=		${WRKDIR}/galaxa

USE_X11=	yes

post-patch:
	@${CP} ${WRKSRC}/makefile ${WRKSRC}/Makefile

pre-install:
	${MKDIR} ${PREFIX}/share/doc/galaxa
	${CP} ${WRKSRC}/README.txt ${PREFIX}/share/doc/galaxa

.include "../../mk/bsd.pkg.mk"
