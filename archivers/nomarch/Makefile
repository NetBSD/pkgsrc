# $NetBSD: Makefile,v 1.4 2003/09/19 12:57:38 jmmv Exp $
#

DISTNAME=	nomarch-1.3
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SUNSITE:=utils/compress/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://rus.members.beeb.net/nomarch.html
COMMENT=	Free replacement for the arc program

USE_BUILDLINK2=	YES
MAKE_FLAGS+=	PREFIX=${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nomarch ${PREFIX}/bin/nomarch
	${INSTALL_DATA} ${WRKSRC}/nomarch.1 ${PREFIX}/man/man1/nomarch.1

.include "../../mk/bsd.pkg.mk"
