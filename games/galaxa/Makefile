# $NetBSD: Makefile,v 1.22 2017/08/01 17:40:11 wiz Exp $
#

DISTNAME=	galaxa.0.1
PKGNAME=	galaxa-0.1
PKGREVISION=	3
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.billsgames.com/unix/x/galaxa/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://web.archive.org/web/2/http://www.newbreedsoftware.com/galaxa/
COMMENT=	Space game based loosely on "Galaga"

WRKSRC=		${WRKDIR}/galaxa
MAKE_FILE=	makefile

INSTALLATION_DIRS+=	bin share/doc/galaxa share/examples/galaxa
INSTALL_MAKE_FLAGS+=	INSTALLROOT=${DESTDIR}${PREFIX}

SETGIDGAME=	yes

SPECIAL_PERMS+=	bin/galaxa ${SETGID_GAMES_PERMS}
CONF_FILES_PERMS+=	${PREFIX}/share/examples/galaxa/galaxa-highs.dat \
			/var/games/galaxa-highs.dat \
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}

pre-install:
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/galaxa

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
