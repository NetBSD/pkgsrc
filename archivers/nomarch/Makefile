# $NetBSD: Makefile,v 1.7 2004/07/28 02:47:35 minskim Exp $
#

DISTNAME=	nomarch-1.3
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SUNSITE:=utils/compress/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://rus.members.beeb.net/nomarch.html
COMMENT=	Free replacement for the arc program

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CC="${CC}"
MAKE_FLAGS+=	CFLAGS="${CFLAGS}"

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nomarch ${PREFIX}/bin/nomarch
	${INSTALL_DATA} ${WRKSRC}/nomarch.1 ${PREFIX}/man/man1/nomarch.1

.include "../../mk/bsd.pkg.mk"
