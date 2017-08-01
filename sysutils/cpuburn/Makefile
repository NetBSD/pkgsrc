# $NetBSD: Makefile,v 1.19 2017/08/01 16:47:44 wiz Exp $
#

DISTNAME=	cpuburn_1_4
PKGNAME=	cpuburn-1.4
PKGREVISION=	4
CATEGORIES=	sysutils
#MASTER_SITES=	http://pages.sbcglobal.net/redelm/
EXTRACT_SUFX=	_tar.gz

MAINTAINER=	abs@NetBSD.org
#HOMEPAGE=	http://pages.sbcglobal.net/redelm/
COMMENT=	CPU load testing utilities for Pentium pro and later

ONLY_FOR_PLATFORM= *-*-i[3456]86

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin share/doc/cpuburn

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/burnBX ${DESTDIR}${PREFIX}/bin/burnBX
	${INSTALL_PROGRAM} ${WRKSRC}/burnK6 ${DESTDIR}${PREFIX}/bin/burnK6
	${INSTALL_PROGRAM} ${WRKSRC}/burnK7 ${DESTDIR}${PREFIX}/bin/burnK7
	${INSTALL_PROGRAM} ${WRKSRC}/burnMMX ${DESTDIR}${PREFIX}/bin/burnMMX
	${INSTALL_PROGRAM} ${WRKSRC}/burnP5 ${DESTDIR}${PREFIX}/bin/burnP5
	${INSTALL_PROGRAM} ${WRKSRC}/burnP6 ${DESTDIR}${PREFIX}/bin/burnP6
	${INSTALL_DATA}	${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/cpuburn/README

.include "../../mk/bsd.pkg.mk"
