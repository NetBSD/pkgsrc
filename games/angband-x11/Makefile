# $NetBSD: Makefile,v 1.2 1998/12/31 15:19:15 tv Exp $
#

DISTNAME=		angband-283
PKGNAME=		angband-x11-2.8.3
CATEGORIES=		games x11
MASTER_SITES=		ftp://export.andrew.cmu.edu/angband/Source/

MAINTAINER=		root@garbled.net

CONFLICTS=		angband-tty-*

WRKSRC=			${WRKDIR}/${DISTNAME}/src
MAKEFILE=		Makefile.std
ALL_TARGET=		angband

PATCHFILES+=		${PKGSRCDIR}/games/angband-tty/patches/patch-*
ALLFILES=		${DISTFILES}	# don't checksum shared patches

do-install:
	${INSTALL} -d -o bin -g games -m 0775 ${PREFIX}/share/angband
	${CP} -R ${WRKDIR}/${DISTNAME}/lib/* ${PREFIX}/share/angband
	chown -R bin:games ${PREFIX}/share/angband
	chmod -R 0664 ${PREFIX}/share/angband/*
	(cd ${PREFIX}/share/angband && chmod 0775 apex bone data edit file help info save user xtra)
	${INSTALL} -c -s -o bin -g games -m 2755 ${WRKSRC}/angband ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
