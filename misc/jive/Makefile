# $NetBSD: Makefile,v 1.18 2006/03/04 21:30:11 jlam Exp $

DISTNAME=		jive-1.1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SUNSITE:=games/amusements/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Filter that converts English text to Jive

WRKSRC=			${WRKDIR}/jive
INSTALLATION_DIRS=	bin man/man1

USE_TOOLS+=		flex

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jive ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jive.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
