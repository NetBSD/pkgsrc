# $NetBSD: Makefile,v 1.16 2006/10/04 21:43:00 wiz Exp $
#

DISTNAME=	galaxa.0.1
PKGNAME=	galaxa-0.1
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.billsgames.com/unix/x/galaxa/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://web.archive.org/web/2/http://www.newbreedsoftware.com/galaxa/
COMMENT=	Space game based loosely on "Galaga"

WRKSRC=		${WRKDIR}/galaxa
MAKE_FILE=	makefile

.include "../../mk/x11.buildlink3.mk"

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/galaxa
	${CP} ${WRKSRC}/README.txt ${PREFIX}/share/doc/galaxa

.include "../../mk/bsd.pkg.mk"
