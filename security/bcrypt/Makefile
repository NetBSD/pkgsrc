# $NetBSD: Makefile,v 1.2 2006/03/04 21:30:33 jlam Exp $
#

DISTNAME=	bcrypt-1.1
CATEGORIES=	security
MASTER_SITES=	http://bcrypt.sourceforge.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
