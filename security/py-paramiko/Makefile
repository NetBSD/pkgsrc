# $NetBSD: Makefile,v 1.44 2022/04/21 11:00:01 wiz Exp $

DISTNAME=	paramiko-2.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/paramiko/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.paramiko.org/
COMMENT=	SSH2 protocol library
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-bcrypt>=3.1.3:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-nacl>=1.0.1:../../security/py-nacl
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-relaxed-[0-9]*:../../devel/py-test-relaxed

PYTHON_VERSIONED_DEPENDENCIES+=	test:test
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
