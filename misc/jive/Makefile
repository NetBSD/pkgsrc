# $NetBSD: Makefile,v 1.4 1998/04/15 10:38:35 agc Exp $
# FreeBSD Id: Makefile,v 1.2 1997/04/02 07:58:25 obrien Exp
#

DISTNAME=	jive-1.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR= games/amusements

MAINTAINER=     obrien@FreeBSD.org

WRKSRC=		${WRKDIR}/jive
MAN1=		jive.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jive ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
