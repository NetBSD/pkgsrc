# $NetBSD: Makefile,v 1.34 2019/11/03 11:45:50 rillig Exp $

DISTNAME=	foolscap-0.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/foolscap/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://foolscap.lothar.com/trac
COMMENT=	RPC protocol for Twisted
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=3.6.1:../../devel/py-ZopeInterface
DEPENDS+=	${PYPKGPREFIX}-twisted>=16.0:../../net/py-twisted

PYTHON_VERSIONS_ACCEPTED=	27 # as of 0.12.7

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
