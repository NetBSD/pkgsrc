# $NetBSD: Makefile,v 1.5 2005/03/24 21:12:54 wiz Exp $

DISTNAME=	jetpack
PKGNAME=	jetpack-1.0
CATEGORIES=	games x11
MASTER_SITES=	ftp://qiclab.scn.rain.com/pub/games/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	root@garbled.net
COMMENT=	Arcade action game for X Windows

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-install:
	@${CHOWN} bin:games ${PREFIX}/bin/jetpack
	@${CHOWN} bin:games ${PREFIX}/share/jetpack
	@${CHMOD} 2755 ${PREFIX}/bin/jetpack
	${INSTALL} -o bin -g games -m 664 /dev/null /var/games/jetpack.scores
	@${CHMOD} 0775 ${PREFIX}/share/jetpack
	${INSTALL_MAN} ${WRKSRC}/jetpack.man ${PREFIX}/man/man6/jetpack.6

.include "../../mk/bsd.pkg.mk"
