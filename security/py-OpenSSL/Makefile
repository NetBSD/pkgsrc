# $NetBSD: Makefile,v 1.59 2022/01/04 20:54:37 wiz Exp $

DISTNAME=	pyOpenSSL-21.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyOpenSSL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyopenssl.org/
COMMENT=	Python interface to the OpenSSL library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cryptography>=3.3:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-six>=1.5.2:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky-[0-9]*:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-pretend-[0-9]*:../../devel/py-pretend
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

# https://github.com/pyca/pyopenssl/issues/656
PYSETUPTESTTARGET=	pytest

.include "../../lang/python/egg.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
