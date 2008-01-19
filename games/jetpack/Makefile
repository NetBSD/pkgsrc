# $NetBSD: Makefile,v 1.10 2008/01/19 09:16:21 wiz Exp $

DISTNAME=	jetpack
PKGNAME=	jetpack-1.0
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	ftp://qiclab.scn.rain.com/pub/games/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Arcade action game for X Windows

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

post-install:
	@${CHOWN} bin:games ${PREFIX}/bin/jetpack
	@${CHOWN} bin:games ${PREFIX}/share/jetpack
	@${CHMOD} 2755 ${PREFIX}/bin/jetpack
	${INSTALL} -o bin -g games -m 664 /dev/null /var/games/jetpack.scores
	@${CHMOD} 0775 ${PREFIX}/share/jetpack
	${INSTALL_MAN} ${WRKSRC}/jetpack.man ${PREFIX}/${PKGMANDIR}/man6/jetpack.6

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
