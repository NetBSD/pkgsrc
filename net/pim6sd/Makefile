# $NetBSD: Makefile,v 1.6 2003/06/06 07:40:41 itojun Exp $

DISTNAME=	pim6sd-20030606a
WRKSRC=		${WRKDIR}/${DISTNAME}/pim6sd/
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	IPv6 PIM sparse mode daemon

post-install:
	${INSTALL_MAN} ${WRKSRC}/pim6stat.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
