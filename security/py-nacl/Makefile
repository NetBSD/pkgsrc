# $NetBSD: Makefile,v 1.1 2017/10/12 12:35:34 adam Exp $

DISTNAME=	PyNaCl-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^Py//:tl}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyNaCl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyca/pynacl/
COMMENT=	Python binding to the Networking and Cryptography (NaCl) library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.4.1:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

MAKE_ENV+=	SODIUM_INSTALL=system

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX}

.include "../../security/libsodium/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
