# $NetBSD: Makefile,v 1.10 2003/03/29 12:41:50 jmmv Exp $
# FreeBSD Id: Makefile,v 1.2 1997/04/02 07:58:25 obrien Exp
#

DISTNAME=		jive-1.1
WRKSRC=			${WRKDIR}/jive
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SUNSITE:=games/amusements/}

MAINTAINER=		packages@netbsd.org
COMMENT=		filter that converts English text to Jive

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jive ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jive.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
