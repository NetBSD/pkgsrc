# $NetBSD: Makefile,v 1.8 2003/06/02 01:21:34 jschauma Exp $
#

DISTNAME=	rio007
PKGNAME=	rio-1.07
WRKSRC=		${WRKDIR}/rio107
CATEGORIES=	audio
MASTER_SITES=	http://www.world.co.uk/sba/
EXTRACT_SUFX=	.tgz

MAINTAINER=     tech-pkg@netbsd.org
HOMEPAGE=       http://www.world.co.uk/sba/rio.htm
COMMENT=	utility to display and manage files on the Diamond Rio PMP300

ONLY_FOR_PLATFORM=	NetBSD-*-i386

MAKEFILE=	makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rio ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/rio
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/rio
	${SED} -e 's|@AWK@|${AWK}|g' ${FILESDIR}/find-lpt-port > ${PREFIX}/bin/find-lpt-port
	${CHMOD} 755 ${PREFIX}/bin/find-lpt-port

.include "../../mk/bsd.pkg.mk"
