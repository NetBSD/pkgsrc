# $NetBSD: Makefile,v 1.2 1998/12/31 15:19:13 tv Exp $
#

DISTNAME=		angband-283
PKGNAME=		angband-tty-2.8.3
CATEGORIES=		games
MASTER_SITES=		ftp://export.andrew.cmu.edu/angband/Source/

MAINTAINER=		root@garbled.net

CONFLICTS=		angband-x11-*

WRKSRC=			${WRKDIR}/${DISTNAME}/src
MAKEFILE=		Makefile.std
ALL_TARGET=		angband

do-install:
	${INSTALL} -d -o bin -g games -m 0775 ${PREFIX}/share/angband
	${CP} -R ${WRKDIR}/${DISTNAME}/lib/* ${PREFIX}/share/angband
	chown -R bin:games ${PREFIX}/share/angband
	chmod -R 0664 ${PREFIX}/share/angband/*
	(cd ${PREFIX}/share/angband && chmod 0775 apex bone data edit file help info save user xtra)
	${INSTALL} -c -s -o bin -g games -m 2755 ${WRKSRC}/angband ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
