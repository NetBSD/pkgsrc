# $NetBSD: Makefile,v 1.4 2008/06/20 01:09:33 joerg Exp $
#

DISTNAME=	bcrypt-1.1
CATEGORIES=	security
MASTER_SITES=	http://bcrypt.sourceforge.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bcrypt.sourceforge.net/
COMMENT=	Cross platform file encryption utility

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=	bcrypt

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bcrypt ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bcrypt.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
