# $NetBSD: Makefile,v 1.9 2005/05/16 01:15:33 jlam Exp $
#

DISTNAME=	cpuburn_1_4
PKGNAME=	cpuburn-1.4
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://pages.sbcglobal.net/redelm/
EXTRACT_SUFX=	_tar.gz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://pages.sbcglobal.net/redelm/
COMMENT=	CPU load testing utilities for Pentium pro and later

ONLY_FOR_PLATFORM= *-*-i[3456]86
EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} | ${GTAR} -xf -

PKGSRC_USE_TOOLS+=	gtar

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
