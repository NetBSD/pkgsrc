# $NetBSD: Makefile,v 1.39 2020/05/17 19:34:13 adam Exp $

DISTNAME=	paramiko-2.7.1
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
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-relaxed-[0-9]*:../../devel/py-test-relaxed

PYTHON_VERSIONED_DEPENDENCIES=	test:test

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
