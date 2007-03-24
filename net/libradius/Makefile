# $NetBSD: Makefile,v 1.10 2007/03/24 19:21:29 joerg Exp $

DISTNAME=	libradius-linux-20040827
PKGNAME=	${DISTNAME:S/-linux//}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://portal-to-web.de/tacacs/

MAINTAINER=	manu@NetBSD.org
COMMENT=	RADIUS client library

CONFLICTS+=	inn-[0-9]*

WRKSRC=		${WRKDIR}/libradius-linux

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/man3

.include "../../mk/bsd.pkg.mk"
