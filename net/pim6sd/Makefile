# $NetBSD: Makefile,v 1.7 2003/07/17 22:51:37 grant Exp $

DISTNAME=	pim6sd-20030606a
WRKSRC=		${WRKDIR}/${DISTNAME}/pim6sd/
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	IPv6 PIM sparse mode daemon

post-install:
	${INSTALL_MAN} ${WRKSRC}/pim6stat.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
