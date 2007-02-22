# $NetBSD: Makefile,v 1.9 2007/02/22 19:26:55 wiz Exp $

DISTNAME=	libradius-linux-20040827
PKGNAME=	${DISTNAME:S/-linux//}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://portal-to-web.de/tacacs/

MAINTAINER=	manu@NetBSD.org
COMMENT=	RADIUS client library

CONFLICTS+=	inn-[0-9]*

WRKSRC=		${WRKDIR}/libradius-linux

.include "../../mk/bsd.pkg.mk"
