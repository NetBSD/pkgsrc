# $NetBSD: Makefile,v 1.74 2025/01/13 08:41:20 adam Exp $

DISTNAME=	pyopenssl-25.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyopenssl/OpenSSL/}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyopenssl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyopenssl.org/
COMMENT=	Python interface to the OpenSSL library
LICENSE=	apache-2.0

WHEEL_NAME=	${DISTNAME:S/openssl/OpenSSL/}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cryptography>=41.0.5:../../security/py-cryptography
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky-[0-9]*:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-pretend-[0-9]*:../../devel/py-pretend

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 313
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.9:../../devel/py-typing-extensions
.endif

# 506 passed, 1 skipped, 6 warnings, 3 errors
# one test failure reported at: https://github.com/pyca/pyopenssl/issues/656

.include "../../lang/python/wheel.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
