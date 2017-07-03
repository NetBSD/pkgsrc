# $NetBSD: Makefile,v 1.46 2017/07/03 21:37:29 wiz Exp $

DISTNAME=	pyOpenSSL-17.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyOpenSSL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyca/pyopenssl/
COMMENT=	Python interface to the OpenSSL library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cryptography>=0.3:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-six>=1.5.2:../../lang/py-six
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-pretend-[0-9]*:../../devel/py-pretend

# https://github.com/pyca/pyopenssl/issues/656
do-test:
	cd ${WRKSRC} && PYTHONPATH=src py.test-${PYVERSSUFFIX} -v

.include "../../lang/python/egg.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
