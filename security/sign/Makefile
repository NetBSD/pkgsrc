# $NetBSD: Makefile,v 1.3 2004/10/03 00:18:13 tv Exp $
#

DISTNAME=	sign-1.0.4
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://swapped.cc/sign/files/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://swapped.cc/sign/
COMMENT=	File signing and signature verification utility

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sign ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/sign.1 ${PREFIX}/man/man1
	${LN} -sf ${PREFIX}/bin/sign ${PREFIX}/bin/unsign

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
