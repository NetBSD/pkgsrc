# $NetBSD: Makefile,v 1.3 2007/01/07 09:14:09 rillig Exp $
#

DISTNAME=	bcrypt-1.1
CATEGORIES=	security
MASTER_SITES=	http://bcrypt.sourceforge.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bcrypt.sourceforge.net/
COMMENT=	Cross platform file encryption utility

PKG_INSTALLATION_TYPES= overwrite pkgviews

BUILD_TARGET=	bcrypt

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bcrypt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bcrypt.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
