# $NetBSD: Makefile,v 1.46 2022/07/13 20:06:23 adam Exp $

DISTNAME=	paramiko-2.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/paramiko/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.paramiko.org/
COMMENT=	SSH2 protocol library
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-bcrypt>=3.1.3:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-cryptography>=2.5:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-nacl>=1.0.1:../../security/py-nacl
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=2.0.0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=4.4.2:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-relaxed>=1.1.5:../../devel/py-test-relaxed
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.28.0:../../devel/py-test-xdist

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-bcrypt

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
