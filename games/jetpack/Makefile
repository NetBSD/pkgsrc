# $NetBSD: Makefile,v 1.7 2006/12/27 13:37:36 joerg Exp $

DISTNAME=	jetpack
PKGNAME=	jetpack-1.0
PKGREVISION=	1
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

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
