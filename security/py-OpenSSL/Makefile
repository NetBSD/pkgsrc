# $NetBSD: Makefile,v 1.77 2025/05/18 09:58:37 wiz Exp $

DISTNAME=	pyopenssl-25.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyopenssl/OpenSSL/}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyopenssl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyopenssl.org/
COMMENT=	Python interface to the OpenSSL library
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cryptography>=41.0.5:../../security/py-cryptography
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky-[0-9]*:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-pretend-[0-9]*:../../devel/py-pretend

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 313
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.9:../../devel/py-typing-extensions
.endif

# as of 25.1.0
# 1 failed, 460 passed, 1 skipped, 364 warnings, 3 errors

.include "../../lang/python/wheel.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
