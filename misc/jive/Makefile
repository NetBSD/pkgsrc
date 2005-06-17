# $NetBSD: Makefile,v 1.16 2005/06/17 03:50:22 jlam Exp $

DISTNAME=		jive-1.1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SUNSITE:=games/amusements/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Filter that converts English text to Jive

WRKSRC=			${WRKDIR}/jive
INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jive ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jive.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
