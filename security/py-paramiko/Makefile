# $NetBSD: Makefile,v 1.22 2014/06/12 00:43:28 gls Exp $

DISTNAME=		paramiko-1.14.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		security
MASTER_SITES=		http://pypi.python.org/packages/source/p/paramiko/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/paramiko/paramiko/
COMMENT=		SSH2 protocol library
LICENSE=		gnu-lgpl-v2.1

DEPENDS+=		${PYPKGPREFIX}-crypto>=2.1:../../security/py-crypto
DEPENDS+=		${PYPKGPREFIX}-ecdsa>=0.9:../../security/py-ecdsa

PYDISTUTILSPKG=	yes
REPLACE_PYTHON=	paramiko/rng*.py

PYTHON_VERSIONS_INCOMPATIBLE=	33 34

do-test:
	(cd ${WRKSRC} && ${PYTHONBIN} test.py)

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
