# $NetBSD: Makefile,v 1.15 2005/03/24 21:12:57 wiz Exp $

DISTNAME=		jive-1.1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SUNSITE:=games/amusements/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Filter that converts English text to Jive

WRKSRC=			${WRKDIR}/jive

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jive ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jive.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
