# $NetBSD: Makefile,v 1.8 2003/10/21 08:37:19 itojun Exp $

DISTNAME=	pim6sd-20031021a
WRKSRC=		${WRKDIR}/${DISTNAME}/pim6sd/
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	IPv6 PIM sparse mode daemon

post-install:
	${INSTALL_MAN} ${WRKSRC}/pim6stat.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
