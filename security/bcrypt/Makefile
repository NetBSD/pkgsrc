# $NetBSD: Makefile,v 1.1.1.1 2005/09/03 22:45:51 xtraeme Exp $
#

DISTNAME=	bcrypt-1.1
CATEGORIES=	security
MASTER_SITES=	http://bcrypt.sourceforge.net/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://bcrypt.sourceforge.net/
COMMENT=	Cross platform file encryption utility

PKG_INSTALLATION_TYPES= overwrite pkgviews

BUILD_TARGET=	bcrypt

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bcrypt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bcrypt.1 ${PREFIX}/man/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
