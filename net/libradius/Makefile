# $NetBSD: Makefile,v 1.16 2014/02/24 12:43:11 wiedi Exp $

DISTNAME=	libradius-linux-20040827
PKGNAME=	${DISTNAME:S/-linux//}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://portal-to-web.de/tacacs/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	RADIUS client library

USE_FEATURES+=	cdefs

CONFLICTS+=	inn-[0-9]*

WRKSRC=		${WRKDIR}/libradius-linux

CPPFLAGS.SunOS+=	-Du_int32_t=uint32_t

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/man3 ${PKGMANDIR}/man5

.include "../../mk/bsd.pkg.mk"
