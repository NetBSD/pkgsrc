# $NetBSD: Makefile,v 1.11 2003/11/12 03:39:39 jschauma Exp $
#

DISTNAME=	base64-1.3
PKGNAME=	${DISTNAME}
PKGREVISION=	1
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
