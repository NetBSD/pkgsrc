# $NetBSD: Makefile,v 1.18 2003/09/17 19:40:21 grant Exp $
#

DISTNAME=		angband-283
PKGNAME=		angband-tty-2.8.3
WRKSRC=			${WRKDIR}/${DISTNAME}/src
CATEGORIES=		games
MASTER_SITES=		ftp://export.andrew.cmu.edu/angband/Source/ \
			ftp://ftp.greyhelm.com/pub/Games/Angband/Angband-2.7.x/Source/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${SPOILERFILE}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.phial.com/angband/
COMMENT=		Tolkien based variant of Moria for tty/console displays

CONFLICTS=		angband-x11-[0-9]*

USE_BUILDLINK2=		# defined
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
MAKEFILE=		Makefile.std
ALL_TARGET=		angband

SPOILERFILE=		angband-spoilers.tar.gz

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
USE_PKGSRC_GCC=		# defined
.endif

do-install:
	${INSTALL} -d -o bin -g games -m 0775 ${PREFIX}/share/angband
	${CP} -R ${WRKDIR}/${DISTNAME}/lib/* ${PREFIX}/share/angband
	cd ${PREFIX}/share/angband/help && \
		${PAX} -O -zrf ${DISTDIR}/${SPOILERFILE}
	${CHOWN} -R bin:games ${PREFIX}/share/angband
	${CHMOD} -R 0664 ${PREFIX}/share/angband/*
	cd ${PREFIX}/share/angband && ${CHMOD} 0775 apex bone data edit file help info save user xtra
	${INSTALL} -c -s -o bin -g games -m 2755 ${WRKSRC}/angband ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
