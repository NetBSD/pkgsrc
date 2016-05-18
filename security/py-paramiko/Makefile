# $NetBSD: Makefile,v 1.25 2016/05/18 12:01:53 he Exp $

DISTNAME=		paramiko-1.15.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		security
MASTER_SITES=		http://pypi.python.org/packages/source/p/paramiko/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/paramiko/paramiko/
COMMENT=		SSH2 protocol library
LICENSE=		gnu-lgpl-v2.1

DEPENDS+=		${PYPKGPREFIX}-crypto>=2.1:../../security/py-crypto
DEPENDS+=		${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=		${PYPKGPREFIX}-ecdsa>=0.11:../../security/py-ecdsa

PYDISTUTILSPKG=	yes
REPLACE_PYTHON=	paramiko/rng*.py

do-test:
	(cd ${WRKSRC} && ${PYTHONBIN} test.py)

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
