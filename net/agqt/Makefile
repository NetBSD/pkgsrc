# $NetBSD: Makefile,v 1.1.1.1.2.1 2002/06/23 18:54:50 jlam Exp $
#

DISTNAME=	agqt-0.5
CATEGORIES=	audio net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qgqt/}
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
