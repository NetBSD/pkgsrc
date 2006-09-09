# $NetBSD: Makefile,v 1.15 2006/09/09 02:42:00 obache Exp $
#

DISTNAME=	galaxa.0.1
PKGNAME=	galaxa-0.1
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/galaxa/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.newbreedsoftware.com/galaxa/
COMMENT=	Space game based loosely on "Galaga"

WRKSRC=		${WRKDIR}/galaxa
MAKE_FILE=	makefile

.include "../../mk/x11.buildlink3.mk"

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/galaxa
	${CP} ${WRKSRC}/README.txt ${PREFIX}/share/doc/galaxa

.include "../../mk/bsd.pkg.mk"
