# $NetBSD: Makefile,v 1.4 2001/02/16 13:30:48 wiz Exp $
#

DISTNAME=	rio007
PKGNAME=	rio-1.07
CATEGORIES=	audio
MASTER_SITES=	http://www.world.co.uk/sba/
EXTRACT_SUFX=	.tgz

MAINTAINER=     packages@netbsd.org
HOMEPAGE=       http://www.world.co.uk/sba/rio.htm
COMMENT=	utility to display and manage files on the Diamond Rio PMP300

ONLY_FOR_PLATFORM=	NetBSD-*-i386

WRKSRC=		${WRKDIR}/rio107

MAKEFILE=	makefile

do-install:
	${BSD_INSTALL_PROGRAM} ${WRKSRC}/rio ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/rio
	${BSD_INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/rio
	${SED} -e 's|@AWK@|${AWK}|g' ${FILESDIR}/find-lpt-port > ${PREFIX}/bin/find-lpt-port
	${CHMOD} 755 ${PREFIX}/bin/find-lpt-port

.include "../../mk/bsd.pkg.mk"
