# $NetBSD: Makefile,v 1.1.1.1 2000/12/21 13:35:49 hubertf Exp $
#

DISTNAME=	rid-1.11
CATEGORIES=	security net
MASTER_SITES=	http://www.theorygroup.com/Software/RID/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.theorygroup.com/Software/RID/

GNU_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rid ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/rid.conf ${PREFIX}/etc
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rid
	${INSTALL_DATA} ${WRKSRC}/BUGS ${WRKSRC}/CHANGES \
		${WRKSRC}/COPYRIGHT ${WRKSRC}/CREDITS ${WRKSRC}/README \
		${PREFIX}/share/doc/rid

.include "../../mk/bsd.pkg.mk"
