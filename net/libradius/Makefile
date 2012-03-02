# $NetBSD: Makefile,v 1.14 2012/03/02 16:28:07 hans Exp $

DISTNAME=	libradius-linux-20040827
PKGNAME=	${DISTNAME:S/-linux//}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://portal-to-web.de/tacacs/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	RADIUS client library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_FEATURES+=	cdefs

CONFLICTS+=	inn-[0-9]*

WRKSRC=		${WRKDIR}/libradius-linux

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/man3 ${PKGMANDIR}/man5

.include "../../mk/bsd.pkg.mk"
