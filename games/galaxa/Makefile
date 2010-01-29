# $NetBSD: Makefile,v 1.19 2010/01/29 23:05:34 joerg Exp $
#

DISTNAME=	galaxa.0.1
PKGNAME=	galaxa-0.1
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.billsgames.com/unix/x/galaxa/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://web.archive.org/web/2/http://www.newbreedsoftware.com/galaxa/
COMMENT=	Space game based loosely on "Galaga"

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/galaxa
MAKE_FILE=	makefile

INSTALLATION_DIRS+=	bin share/doc/galaxa
INSTALL_MAKE_FLAGS+=	INSTALLROOT=${DESTDIR}${PREFIX}

pre-install:
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/galaxa

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
