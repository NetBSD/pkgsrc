# $NetBSD: Makefile,v 1.4 2004/11/29 00:07:15 tv Exp $
#

DISTNAME=	proxycheck-0.49a
CATEGORIES=	net
MASTER_SITES=	http://www.corpit.ru/mjt/proxycheck/

MAINTAINER=	tv@duh.org
HOMEPAGE=	http://www.corpit.ru/mjt/proxycheck.html
COMMENT=	Tester for open (promiscuous) proxy systems

HAS_CONFIGURE=	YES
MAKE_FLAGS+=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/proxycheck ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/proxycheck.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
