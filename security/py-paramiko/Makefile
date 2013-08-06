# $NetBSD: Makefile,v 1.17 2013/08/06 20:12:18 wiz Exp $

DISTNAME=		paramiko-1.11.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		security
MASTER_SITES=		http://pypi.python.org/packages/source/p/paramiko/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/paramiko/paramiko/
COMMENT=		SSH2 protocol library
LICENSE=		gnu-lgpl-v2.1

DEPENDS+=		${PYPKGPREFIX}-crypto>=2.1:../../security/py-crypto

PYDISTUTILSPKG=	yes
REPLACE_PYTHON=	paramiko/rng*.py

do-test:
	(cd ${WRKSRC} && ${PYTHONBIN} test.py)

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
