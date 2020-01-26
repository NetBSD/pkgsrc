# $NetBSD: Makefile,v 1.12 2020/01/26 17:31:53 rillig Exp $
#

DISTNAME=	proxycheck-0.49a
CATEGORIES=	net
MASTER_SITES=	http://www.corpit.ru/mjt/proxycheck/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.corpit.ru/mjt/proxycheck.html
COMMENT=	Tester for open (promiscuous) proxy systems

HAS_CONFIGURE=	YES
MAKE_FLAGS+=	CC=${CC:Q} CFLAGS=${CFLAGS:M*:Q} LDFLAGS=${LDFLAGS:M*:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/proxycheck ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/proxycheck.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
