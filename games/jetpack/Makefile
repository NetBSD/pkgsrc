# $NetBSD: Makefile,v 1.14 2019/01/20 08:09:29 dholland Exp $

DISTNAME=	jetpack
PKGNAME=	jetpack-1.0
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	ftp://qiclab.scn.rain.com/pub/games/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Arcade action game for X Windows

USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes
USE_GAMESGROUP=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6 share/jetpack

SPECIAL_PERMS+=	bin/jetpack ${SETGID_GAMES_PERMS}

CONF_FILES_PERM+=	/dev/null /var/games/jetpack.scores \
			${GAMES_USER} ${GAMES_GROUP} 0664
OWN_DIRS_PERMS+=	${PREFIX}/share/jetpack ${GAMES_USER} ${GAMES_GROUP} 0775

post-install:
	${INSTALL_MAN} ${WRKSRC}/jetpack.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/jetpack.6

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
