# $NetBSD: Makefile,v 1.9 2012/03/02 16:25:39 hans Exp $
#

DISTNAME=	error-0.0
CATEGORIES=	devel
MASTER_SITES=	# ftp://ftp.gw.com/pub/people/christos/

MAINTAINER=	christos@NetBSD.org
COMMENT=	Insert compiler errors in source files as comments

PKG_DESTDIR_SUPPORT=	user-destdir

USE_FEATURES+=		cdefs
USE_BSD_MAKEFILE=	yes
INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.pkg.mk"
