# $NetBSD: Makefile,v 1.5 2003/06/02 01:17:47 jschauma Exp $

DISTNAME=	pim6sd-20020403a
WRKSRC=		${WRKDIR}/${DISTNAME}/pim6sd/
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	IPv6 PIM sparse mode daemon

# does it seem right?
LICENSE=	no-commercial-use

post-install:
	${INSTALL_MAN} ${WRKSRC}/pim6stat.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
