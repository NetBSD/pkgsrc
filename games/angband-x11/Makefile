# $NetBSD: Makefile,v 1.9 2001/12/15 20:25:36 agc Exp $
#

DISTNAME=		angband-283
PKGNAME=		angband-x11-2.8.3
CATEGORIES=		games x11
MASTER_SITES=		ftp://export.andrew.cmu.edu/angband/Source/ \
			ftp://ftp.greyhelm.com/pub/Games/Angband/Angband-2.7.x/Source/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} angband-spoilers.tar.gz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.phial.com/angband/
COMMENT=		Tolkien based variant of Moria for X11 displays

CONFLICTS=		angband-tty-[0-9]*

EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
WRKSRC=			${WRKDIR}/${DISTNAME}/src
MAKEFILE=		Makefile.std
ALL_TARGET=		angband
USE_X11=		yes

PATCHFILES+=		${_PKGSRCDIR}/games/angband-tty/patches/patch-*
ALLFILES=		${DISTFILES}	# don't checksum shared patches

SPOILERFILE=		angband-spoilers.tar.gz

do-install:
	${INSTALL} -d -o bin -g games -m 0775 ${PREFIX}/share/angband
	${CP} -R ${WRKDIR}/${DISTNAME}/lib/* ${PREFIX}/share/angband
	cd ${PREFIX}/share/angband/help && \
		${PAX} -rzf ${DISTDIR}/${SPOILERFILE}
	${CHOWN} -R bin:games ${PREFIX}/share/angband
	${CHMOD} -R 0664 ${PREFIX}/share/angband/*
	(cd ${PREFIX}/share/angband && ${CHMOD} 0775 apex bone data edit file help info save user xtra)
	${INSTALL} -c -s -o bin -g games -m 2755 ${WRKSRC}/angband ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
