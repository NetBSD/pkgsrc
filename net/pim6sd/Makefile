# $NetBSD: Makefile,v 1.12 2006/06/21 18:31:21 minskim Exp $

DISTNAME=	pim6sd-20031021a
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	IPv6 PIM sparse mode daemon

WRKSRC=		${WRKDIR}/${DISTNAME}/pim6sd/
USE_TOOLS+=	lex yacc

post-install:
	${INSTALL_MAN} ${WRKSRC}/pim6stat.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
