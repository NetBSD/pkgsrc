# $NetBSD: Makefile,v 1.9 2001/02/17 18:09:08 wiz Exp $
# FreeBSD Id: Makefile,v 1.2 1997/04/02 07:58:25 obrien Exp
#

DISTNAME=		jive-1.1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SUNSITE:=games/amusements/}

MAINTAINER=		packages@netbsd.org
COMMENT=		filter that converts English text to Jive

WRKSRC=			${WRKDIR}/jive

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jive ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jive.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
