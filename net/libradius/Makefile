# $NetBSD: Makefile,v 1.8 2005/11/22 16:14:14 tron Exp $

DISTNAME=	libradius-linux-20040827
PKGNAME=	${DISTNAME:S/-linux//}
PKGREVISION= 	2
CATEGORIES=	net
MASTER_SITES=	http://portal-to-web.de/tacacs/

MAINTAINER=	manu@NetBSD.org
COMMENT=	RADIUS client library

CONFLICTS+=	inn-[0-9]*

WRKSRC=		${WRKDIR}/libradius-linux

.include "../../mk/bsd.pkg.mk"
