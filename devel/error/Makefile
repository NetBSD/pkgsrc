# $NetBSD: Makefile,v 1.7 2008/12/18 15:29:11 joerg Exp $
#

DISTNAME=	error-0.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gw.com/pub/people/christos/

MAINTAINER=	christos@NetBSD.org
COMMENT=	Insert compiler errors in source files as comments

PKG_DESTDIR_SUPPORT=	user-destdir

USE_BSD_MAKEFILE=	yes
INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.pkg.mk"
