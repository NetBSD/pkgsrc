# $NetBSD: Makefile,v 1.1.1.1 2004/05/16 00:00:28 xtraeme Exp $
#

DISTNAME=	sign-1.0.4
CATEGORIES=	security
MASTER_SITES=	http://swapped.cc/sign/files/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://swapped.cc/sign/files/
COMMENT=	File signing and signature verification utility

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sign ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/sign.1 ${PREFIX}/man/man1
	${LN} -sf ${PREFIX}/bin/sign ${PREFIX}/bin/unsign

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
