# $NetBSD: Makefile,v 1.3 2002/04/03 05:37:00 itojun Exp $

DISTNAME=	pim6sd-20020403a
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	packages@netbsd.org
COMMENT=	IPv6 PIM sparse mode daemon

# does it seem right?
LICENSE=	no-commercial-use

WRKSRC=		${WRKDIR}/${DISTNAME}/pim6sd/

post-install:
	${INSTALL_MAN} ${WRKSRC}/pim6stat.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
