# $NetBSD: Makefile,v 1.15 2004/12/03 15:14:52 wiz Exp $
#

DISTNAME=	base64-1.3
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://www.fourmilab.ch/webtools/base64/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.fourmilab.ch/webtools/base64/
COMMENT=	Encode and decode base64 files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
BUILD_TARGET=	prog
USE_BUILDLINK3=	yes

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/base64 ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/base64.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
