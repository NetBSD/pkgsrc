# $NetBSD: Makefile,v 1.7 2002/11/14 23:39:09 jlam Exp $
#

DISTNAME=	base64-1.3
PKGNAME=	${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	http://www.fourmilab.ch/webtools/base64/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fourmilab.ch/webtools/base64/
COMMENT=	encode and decode base64 files

CONFLICTS=	openssl-[0-9]*
GNU_CONFIGURE=	yes
ALL_TARGET=	prog
USE_BUILDLINK2=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/base64 ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/base64.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
