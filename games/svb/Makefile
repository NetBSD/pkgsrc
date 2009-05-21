# $NetBSD: Makefile,v 1.15 2009/05/21 10:58:05 zafer Exp $

DISTNAME=		svb
PKGNAME=		svb-1.0
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		http://ring.nict.go.jp/archives/X/opengroup/R5contrib/
EXTRACT_SUFX=		.shar.Z

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Spy Vs. Bob, the timeless classic

WRKSRC=			${WRKDIR}
USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

post-install:
	${INSTALL_GAME_DATA} /dev/null /var/games/svb.scorefile
	${CHOWN} ${GAMEOWN}:${GAMEGRP} ${PREFIX}/bin/svb
	${CHMOD} ${GAMEMODE} ${PREFIX}/bin/svb
	${INSTALL_MAN} ${WRKSRC}/svb.man ${PREFIX}/${PKGMANDIR}/man6/svb.6

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
