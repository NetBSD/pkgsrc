# $NetBSD: Makefile,v 1.1.1.1 1999/08/16 18:18:19 rh Exp $
#

DISTNAME=	base64
PKGNAME=	base64-1.0
CATEGORIES=	converters
MASTER_SITES=	http://www.fourmilab.ch/webtools/base64/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fourmilab.ch/webtools/base64/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/base64 ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/base64.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
