# $NetBSD: Makefile,v 1.3 1998/08/27 14:06:08 garbled Exp $

DISTNAME=		Maelstrom-1.4.3-L2.0.6-src.tar.gz
PKGNAME=		maelstrom-2.0.6
CATEGORIES=		games x11
MASTER_SITES+=		ftp://ftp.devolution.com/pub/maelstrom/
MASTER_SITES+=		ftp://ftp.devolution.com/pub/maelstrom/Maelstrom-binaries/
MASTER_SITES+=		ftp://ftp.devolution.com/pub/maelstrom/Add-Ons/
DISTFILES=		${DISTNAME} ${STREK} ${SWARS} ${ESOUND}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.ambrosiasw.com/Products/Maelstrom.html

ESOUND=			Maelstrom-Sounds-L2.0.0.tar.gz
STREK=			Star_Trek.tar.gz
SWARS=			Star_Wars.tar.gz

EXTRACT_ONLY=		${DISTNAME}

WRKSRC=			${WRKDIR}/Maelstrom

USE_X11=		yes
MAKE_ENV+=		BINOWN=${BINOWN} BINGRP=${BINGRP}

post-install:
	cd ${PREFIX}/share/maelstrom && \
	pax -rzf ${DISTDIR}/${ESOUND} -p m && \
	pax -rzf ${DISTDIR}/${STREK} -p m && \
	pax -rzf ${DISTDIR}/${SWARS} -p m
	chown ${BINOWN}:games ${PREFIX}/bin/Maelstrom
	chmod 2755 ${PREFIX}/bin/Maelstrom
	chown ${BINOWN}:games ${PREFIX}/share/maelstrom/Maelstrom-Scores
	chmod 0664 ${PREFIX}/share/maelstrom/Maelstrom-Scores
	${INSTALL_DATA} ${WRKSRC}/README.* ${PREFIX}/share/maelstrom
	${INSTALL_PROGRAM} ${WRKSRC}/netplayd/netplayd ${PREFIX}/bin/Maelstrom_netplayd

.include "../../mk/bsd.pkg.mk"
