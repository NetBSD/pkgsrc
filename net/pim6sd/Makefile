# $NetBSD: Makefile,v 1.9 2004/01/20 12:22:20 agc Exp $

DISTNAME=	pim6sd-20031021a
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	IPv6 PIM sparse mode daemon

WRKSRC=		${WRKDIR}/${DISTNAME}/pim6sd/

post-install:
	${INSTALL_MAN} ${WRKSRC}/pim6stat.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
