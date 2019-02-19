# $NetBSD: Makefile,v 1.4 2019/02/19 17:49:24 tm Exp $

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
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

MAKE_ENV+=	SODIUM_INSTALL=system

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX}

.include "../../security/libsodium/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
