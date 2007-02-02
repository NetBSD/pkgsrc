# $NetBSD: Makefile,v 1.17 2007/02/02 18:32:36 joerg Exp $
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

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/galaxa
	${CP} ${WRKSRC}/README.txt ${PREFIX}/share/doc/galaxa

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
