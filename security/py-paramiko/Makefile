# $NetBSD: Makefile,v 1.50 2023/07/31 16:16:48 adam Exp $

DISTNAME=	paramiko-3.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/paramiko/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.paramiko.org/
COMMENT=	SSH2 protocol library
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-bcrypt>=3.2:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-nacl>=1.5:../../security/py-nacl
TEST_DEPENDS+=	${PYPKGPREFIX}-icecream-[0-9]*:../../misc/py-icecream
TEST_DEPENDS+=	${PYPKGPREFIX}-invoke>=2.0:../../sysutils/py-invoke
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=2.0.0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=4.4.2:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-relaxed>=1.1.5:../../devel/py-test-relaxed
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.28.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
