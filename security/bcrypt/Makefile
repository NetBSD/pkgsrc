# $NetBSD: Makefile,v 1.7 2020/01/18 23:35:06 rillig Exp $
#

DISTNAME=	bcrypt-1.1
CATEGORIES=	security
MASTER_SITES=	http://bcrypt.sourceforge.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bcrypt.sourceforge.net/
COMMENT=	Cross platform file encryption utility

BUILD_TARGET=	bcrypt

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bcrypt ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bcrypt.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
