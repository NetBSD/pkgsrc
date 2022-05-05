# $NetBSD: Makefile,v 1.45 2022/05/05 17:59:35 adam Exp $

DISTNAME=	paramiko-2.10.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/paramiko/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.paramiko.org/
COMMENT=	SSH2 protocol library
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-bcrypt>=3.1.3:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-nacl>=1.0.1:../../security/py-nacl
DEPENDS+=	${PYPKGPREFIX}-six>0:../../lang/py-six
#TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-relaxed-[0-9]*:../../devel/py-test-relaxed

PYTHON_VERSIONED_DEPENDENCIES+=	test:test
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
