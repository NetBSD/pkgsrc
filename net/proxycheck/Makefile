# $NetBSD: Makefile,v 1.3 2003/06/11 20:15:14 wiz Exp $
#

DISTNAME=	proxycheck-0.45
CATEGORIES=	net
MASTER_SITES=	http://www.corpit.ru/mjt/proxycheck/

MAINTAINER=	tv@pobox.com
HOMEPAGE=	http://www.corpit.ru/mjt/proxycheck.html
COMMENT=	Tester for open (promiscuous) proxy systems

MAKE_FLAGS+=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/proxycheck ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/proxycheck.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
