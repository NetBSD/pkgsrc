# $NetBSD: Makefile,v 1.7 1998/07/28 10:56:08 frueauf Exp $
# FreeBSD Id: Makefile,v 1.2 1997/04/02 07:58:25 obrien Exp
#

DISTNAME=		jive-1.1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/amusements

MAINTAINER=		packages@netbsd.org

WRKSRC=			${WRKDIR}/jive

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jive ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jive.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
