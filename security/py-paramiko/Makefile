# $NetBSD: Makefile,v 1.27 2016/06/08 17:43:38 wiz Exp $

DISTNAME=		paramiko-1.15.3
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
