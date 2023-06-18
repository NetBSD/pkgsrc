# $NetBSD: Makefile,v 1.42 2023/06/18 05:39:37 adam Exp $

DISTNAME=	foolscap-21.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/foolscap/}

MAINTAINER=	kamel.derouiche@gmail.com
# This homepage is correct, but it is out of date.
HOMEPAGE=	https://foolscap.lothar.com/trac
#HOMEPAGE=	https://pypi.org/project/foolscap/
COMMENT=	RPC protocol for Twisted
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-zope.interface>=3.6.1:../../devel/py-zope.interface

PYTHON_VERSIONS_INCOMPATIBLE=	27

# \todo Restore tests
#TEST_TARGET=	test

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

INSTALLATION_DIRS+=	share/doc/py-foolscap

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt \
		${DESTDIR}${PREFIX}/share/doc/py-foolscap
	${INSTALL_DATA} ${WRKSRC}/doc/*.rst \
		${DESTDIR}${PREFIX}/share/doc/py-foolscap

.include "../../lang/python/egg.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
