# $NetBSD: Makefile,v 1.4 2000/01/02 03:20:06 wiz Exp $
#

DISTNAME=		angband-283
PKGNAME=		angband-tty-2.8.3
CATEGORIES=		games
MASTER_SITES=		ftp://export.andrew.cmu.edu/angband/Source/

MAINTAINER=		root@garbled.net

WRKSRC=			${WRKDIR}/${DISTNAME}/src
MAKEFILE=		Makefile.std
ALL_TARGET=		angband

do-install:
	${INSTALL} -d -o bin -g games -m 0775 ${PREFIX}/share/angband
	${CP} -R ${WRKDIR}/${DISTNAME}/lib/* ${PREFIX}/share/angband
	${CHOWN} -R bin:games ${PREFIX}/share/angband
	${CHMOD} -R 0664 ${PREFIX}/share/angband/*
	(cd ${PREFIX}/share/angband && ${CHMOD} 0775 apex bone data edit file help info save user xtra)
	${INSTALL} -c -s -o bin -g games -m 2755 ${WRKSRC}/angband ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
