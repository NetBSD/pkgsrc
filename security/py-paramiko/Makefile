# $NetBSD: Makefile,v 1.28 2017/05/19 14:47:10 he Exp $

DISTNAME=		paramiko-1.18.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_PYPI:=p/paramiko/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/paramiko/paramiko/
COMMENT=		SSH2 protocol library
LICENSE=		gnu-lgpl-v2.1

DEPENDS+=		${PYPKGPREFIX}-crypto>=2.1:../../security/py-crypto
DEPENDS+=		${PYPKGPREFIX}-ecdsa>=0.11:../../security/py-ecdsa

PYDISTUTILSPKG=	yes
REPLACE_PYTHON=	paramiko/rng*.py

do-test:
	(cd ${WRKSRC} && ${PYTHONBIN} test.py)

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
