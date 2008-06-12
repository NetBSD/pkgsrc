# $NetBSD: Makefile,v 1.10 2008/06/12 02:14:41 joerg Exp $
#

DISTNAME=	proxycheck-0.49a
CATEGORIES=	net
MASTER_SITES=	http://www.corpit.ru/mjt/proxycheck/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.corpit.ru/mjt/proxycheck.html
COMMENT=	Tester for open (promiscuous) proxy systems

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES
MAKE_FLAGS+=	CC=${CC:Q} CFLAGS=${CFLAGS:M*:Q} LDFLAGS=${LDFLAGS:M*:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/proxycheck ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/proxycheck.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
