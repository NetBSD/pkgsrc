# $NetBSD: Makefile,v 1.9 2005/12/01 16:41:29 rillig Exp $
#

DISTNAME=	nomarch-1.3
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SUNSITE:=utils/compress/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://rus.members.beeb.net/nomarch.html
COMMENT=	Free replacement for the arc program

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_FLAGS+=	PREFIX=${PREFIX:Q}
MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:M*:Q}

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nomarch ${PREFIX}/bin/nomarch
	${INSTALL_DATA} ${WRKSRC}/nomarch.1 ${PREFIX}/man/man1/nomarch.1

.include "../../mk/bsd.pkg.mk"
