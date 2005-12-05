# $NetBSD: Makefile,v 1.6 2005/12/05 20:50:48 rillig Exp $
#

DISTNAME=	proxycheck-0.49a
CATEGORIES=	net
MASTER_SITES=	http://www.corpit.ru/mjt/proxycheck/

MAINTAINER=	tv@duh.org
HOMEPAGE=	http://www.corpit.ru/mjt/proxycheck.html
COMMENT=	Tester for open (promiscuous) proxy systems

HAS_CONFIGURE=	YES
MAKE_FLAGS+=	CC=${CC:Q} CFLAGS=${CFLAGS:M*:Q} LDFLAGS=${LDFLAGS:M*:Q}

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/proxycheck ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/proxycheck.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
