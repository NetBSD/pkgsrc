# $NetBSD: Makefile,v 1.10 2003/07/21 16:36:11 martti Exp $
#

DISTNAME=	base64-1.3
PKGNAME=	${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	http://www.fourmilab.ch/webtools/base64/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.fourmilab.ch/webtools/base64/
COMMENT=	Encode and decode base64 files

CONFLICTS=	openssl-[0-9]*
GNU_CONFIGURE=	yes
ALL_TARGET=	prog
USE_BUILDLINK2=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/base64 ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/base64.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
