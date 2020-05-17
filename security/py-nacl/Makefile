# $NetBSD: Makefile,v 1.5 2020/05/17 19:34:12 adam Exp $

DISTNAME=	PyNaCl-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl:S/^py//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyNaCl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyca/pynacl/
COMMENT=	Python binding to the Networking and Cryptography (NaCl) library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.4.1:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=3.27.0:../../devel/py-hypothesis

PYTHON_VERSIONED_DEPENDENCIES=	test:test
.include "../../lang/python/versioned_dependencies.mk"

MAKE_ENV+=	SODIUM_INSTALL=system

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX}

.include "../../security/libsodium/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
