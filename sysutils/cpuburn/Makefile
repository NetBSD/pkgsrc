# $NetBSD: Makefile,v 1.3 2002/09/17 17:02:30 abs Exp $
#

DISTNAME=	cpuburn_1_4
PKGNAME=	cpuburn-1.4
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://users.ev1.net/~redelm/
EXTRACT_SUFX=	_tar.gz

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://users.ev1.net/~redelm/
COMMENT=	CPU load testing utilities for Pentium pro and later

ONLY_FOR_PLATFORM= *-*-i386
EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} | ${GTAR} -xf -
WRKSRC=         ${WRKDIR}/${PKGNAME_NOREV}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/burnBX ${PREFIX}/bin/burnBX
	${INSTALL_PROGRAM} ${WRKSRC}/burnK6 ${PREFIX}/bin/burnK6
	${INSTALL_PROGRAM} ${WRKSRC}/burnK7 ${PREFIX}/bin/burnK7
	${INSTALL_PROGRAM} ${WRKSRC}/burnMMX ${PREFIX}/bin/burnMMX
	${INSTALL_PROGRAM} ${WRKSRC}/burnP5 ${PREFIX}/bin/burnP5
	${INSTALL_PROGRAM} ${WRKSRC}/burnP6 ${PREFIX}/bin/burnP6
	${INSTALL_DATA}	${WRKSRC}/README ${PREFIX}/share/doc/cpuburn.README

.include "../../mk/bsd.pkg.mk"
