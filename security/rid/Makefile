# $NetBSD: Makefile,v 1.2 2001/02/17 17:50:06 wiz Exp $
#

DISTNAME=	rid-1.11
CATEGORIES=	security net
MASTER_SITES=	http://www.theorygroup.com/Software/RID/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.theorygroup.com/Software/RID/
COMMENT=	Remote Intrusion Detection to track down compromised hosts

GNU_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rid ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/rid.conf ${PREFIX}/etc
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rid
	${INSTALL_DATA} ${WRKSRC}/BUGS ${WRKSRC}/CHANGES \
		${WRKSRC}/COPYRIGHT ${WRKSRC}/CREDITS ${WRKSRC}/README \
		${PREFIX}/share/doc/rid

.include "../../mk/bsd.pkg.mk"
