# $NetBSD: Makefile,v 1.5 2003/04/10 20:10:17 grant Exp $

DISTNAME=		Maelstrom-1.4.3-L2.0.6-src.tar.gz
PKGNAME=		maelstrom-x11-2.0.6
WRKSRC=			${WRKDIR}/Maelstrom
CATEGORIES=		games x11
MASTER_SITES+=		ftp://ftp.devolution.com/pub/maelstrom/
MASTER_SITES+=		ftp://ftp.devolution.com/pub/maelstrom/Maelstrom-binaries/
MASTER_SITES+=		ftp://ftp.devolution.com/pub/maelstrom/Add-Ons/
DISTFILES=		${DISTNAME} ${STREK} ${SWARS} ${ESOUND}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.ambrosiasw.com/Products/Maelstrom.html
COMMENT=		Incredible, fast moving, high graphics version of asteroids (X11 version)

ESOUND=			Maelstrom-Sounds-L2.0.0.tar.gz
STREK=			Star_Trek.tar.gz
SWARS=			Star_Wars.tar.gz

CONFLICTS=		maelstrom-[0-9]* maelstrom-sdl-[0-9]*

EXTRACT_ONLY=		${DISTNAME}

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
MAKE_ENV+=		BINOWN=${BINOWN} BINGRP=${BINGRP} XPMDIR=${BUILDLINK_PREFIX.xpm}

post-install:
	cd ${PREFIX}/share/maelstrom && \
		${PAX} -O -pm -zrf ${DISTDIR}/${ESOUND} && \
		${PAX} -O -pm -zrf ${DISTDIR}/${STREK} && \
		${PAX} -O -pm -zrf ${DISTDIR}/${SWARS}
	${CHOWN} ${BINOWN}:games ${PREFIX}/bin/Maelstrom
	${CHMOD} 2755 ${PREFIX}/bin/Maelstrom
	${CHOWN} ${BINOWN}:games /var/games/Maelstrom-Scores
	${CHMOD} 0664 /var/games/Maelstrom-Scores
	${INSTALL_DATA} ${WRKSRC}/README.* ${PREFIX}/share/maelstrom
	${INSTALL_PROGRAM} ${WRKSRC}/netplayd/netplayd ${PREFIX}/bin/Maelstrom_netplayd

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
