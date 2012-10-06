# $NetBSD: Makefile,v 1.17 2012/10/06 11:54:56 asau Exp $

DISTNAME=		svb
PKGNAME=		svb-1.0
PKGREVISION=		2
CATEGORIES=		games x11
MASTER_SITES=		http://ring.nict.go.jp/archives/X/opengroup/R5contrib/
EXTRACT_SUFX=		.shar.Z

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Spy Vs. Bob, the timeless classic

WRKSRC=			${WRKDIR}
USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

MAKE_ENV+=	VARBASE=${VARBASE:Q}

SETGIDGAME=	yes

SPECIAL_PERMS+=	bin/svb ${SETGID_GAMES_PERMS}

CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/svb.scorefile \
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}

post-install:
	${INSTALL_MAN} ${WRKSRC}/svb.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/svb.6

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
