# $NetBSD: Makefile,v 1.39 2022/02/13 08:53:44 wiz Exp $

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

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=3.6.1:../../devel/py-ZopeInterface

PYTHON_VERSIONED_DEPENDENCIES+=	twisted

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
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
