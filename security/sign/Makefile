# $NetBSD: Makefile,v 1.7 2006/02/05 23:10:47 joerg Exp $
#

DISTNAME=	sign-1.0.4
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://swapped.cc/sign/files/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://swapped.cc/sign/
COMMENT=	File signing and signature verification utility

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sign ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/sign.1 ${PREFIX}/man/man1
	${LN} -sf ${PREFIX}/bin/sign ${PREFIX}/bin/unsign

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
