# $NetBSD: Makefile,v 1.13 2009/03/22 04:53:40 manu Exp $

DISTNAME=	libradius-linux-20040827
PKGNAME=	${DISTNAME:S/-linux//}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://portal-to-web.de/tacacs/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	RADIUS client library

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	inn-[0-9]*

WRKSRC=		${WRKDIR}/libradius-linux

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/man3 ${PKGMANDIR}/man5

.include "../../mk/bsd.pkg.mk"
