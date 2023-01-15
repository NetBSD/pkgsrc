# $NetBSD: Makefile,v 1.63 2023/01/15 19:40:14 abs Exp $

DISTNAME=	pyOpenSSL-23.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyOpenSSL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyopenssl.org/
COMMENT=	Python interface to the OpenSSL library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cryptography>=38.0.0:../../security/py-cryptography
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky-[0-9]*:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-pretend-[0-9]*:../../devel/py-pretend
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

# https://github.com/pyca/pyopenssl/issues/656
PYSETUPTESTTARGET=	pytest

# test status as of 22.0.0
# 4 failed, 521 passed, 1 skipped, 6 warnings

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
