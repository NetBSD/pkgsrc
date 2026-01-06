# $NetBSD: Makefile,v 1.16 2026/01/06 12:22:01 adam Exp $

DISTNAME=	pynacl-1.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyNaCl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyca/pynacl
COMMENT=	Python binding to the Networking and Cryptography (NaCl) library
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi>=2.0.0:../../devel/py-cffi
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=3.27.0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.10.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.5.0:../../devel/py-test-xdist

MAKE_ENV+=	SODIUM_INSTALL=system

.include "../../security/libsodium/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
