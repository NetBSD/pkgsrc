# $NetBSD: Makefile,v 1.11 2022/10/31 08:11:43 adam Exp $

DISTNAME=	PyNaCl-1.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl:S/^py//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyNaCl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyca/pynacl
COMMENT=	Python binding to the Networking and Cryptography (NaCl) library
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.4.1:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

MAKE_ENV+=	SODIUM_INSTALL=system

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../security/libsodium/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
