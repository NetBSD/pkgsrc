# $NetBSD: Makefile,v 1.7 2001/02/25 04:17:49 hubertf Exp $
#

DISTNAME=	galaxa.0.1
PKGNAME=	galaxa-0.1
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/galaxa/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.newbreedsoftware.com/galaxa/
COMMENT=	Space game based loosely on "Galaga"

WRKSRC=		${WRKDIR}/galaxa
MAKEFILE=	makefile
USE_X11BASE=	yes

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/galaxa
	${CP} ${WRKSRC}/README.txt ${PREFIX}/share/doc/galaxa

.include "../../mk/bsd.pkg.mk"
