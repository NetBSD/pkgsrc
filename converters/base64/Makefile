# $NetBSD: Makefile,v 1.6 2001/09/27 23:17:50 jlam Exp $
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
USE_BUILDLINK_ONLY=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/base64 ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/base64.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
