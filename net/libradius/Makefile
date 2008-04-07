# $NetBSD: Makefile,v 1.11 2008/04/07 17:28:55 joerg Exp $

DISTNAME=	libradius-linux-20040827
PKGNAME=	${DISTNAME:S/-linux//}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://portal-to-web.de/tacacs/

MAINTAINER=	manu@NetBSD.org
COMMENT=	RADIUS client library

CONFLICTS+=	inn-[0-9]*

WRKSRC=		${WRKDIR}/libradius-linux

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/man3 ${PKGMANDIR}/man5

.include "../../mk/bsd.pkg.mk"
