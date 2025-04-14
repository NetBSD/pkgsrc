# $NetBSD: Makefile,v 1.14 2025/04/14 05:08:07 adam Exp $

DISTNAME=	cryptography-3.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cryptography/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyca/cryptography
COMMENT=	Cryptographic recipes and primitives for Python (non-Rust version)
LICENSE=	apache-2.0 OR modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi>=0:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-cryptography_vectors-[0-9]*:../../security/py-cryptography_vectors
TEST_DEPENDS+=	${PYPKGPREFIX}-iso8601-[0-9]*:../../time/py-iso8601
TEST_DEPENDS+=	${PYPKGPREFIX}-pretend-[0-9]*:../../devel/py-pretend
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

.include "../../lang/python/wheel.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
