# $NetBSD: Makefile,v 1.1.1.1 2001/07/29 01:12:58 hubertf Exp $
#

DISTNAME=	agqt-0.5
CATEGORIES=	audio net
MASTER_SITES=	http://prdownloads.sourceforge.net/agqt/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://agqt.sourceforge.net/
COMMENT=	AudioGalaxy Query Tool

WRKSRC=		${WRKDIR}/agqt

do-build:
		cd ${WRKSRC}/am ; make
		cd ${WRKSRC}/ag ; make

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/ag/ag ${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/am/am ${PREFIX}/bin
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/agqt
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/agqt
		${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/agqt
		${INSTALL_DATA} ${WRKSRC}/agrc.sample ${PREFIX}/share/doc/agqt

.include "../../mk/bsd.pkg.mk"
