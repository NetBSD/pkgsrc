# $NetBSD: Makefile,v 1.20 2016/07/09 13:04:00 wiz Exp $

DISTNAME=	foolscap-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/foolscap/}

MAINTAINER=	kamel.derouiche@gmail.com
#MAINTAINER+=	gdt@NetBSD.org
HOMEPAGE=	http://foolscap.lothar.com/trac
COMMENT=	Foolscap contains an RPC protocol for Twisted
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=3.6.1:../../devel/py-ZopeInterface
DEPENDS+=	${PYPKGPREFIX}-twisted>=16.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-twisted

TEST_TARGET=	test

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	share/doc/py-foolscap

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt \
		${DESTDIR}${PREFIX}/share/doc/py-foolscap
	${INSTALL_DATA} ${WRKSRC}/doc/*.rst \
		${DESTDIR}${PREFIX}/share/doc/py-foolscap

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
