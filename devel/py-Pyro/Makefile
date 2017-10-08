# $NetBSD: Makefile,v 1.21 2017/10/08 10:21:57 adam Exp $

DISTNAME=	Pyro4-4.62
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pyro4/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/irmen/Pyro4
COMMENT=	Distributed Object Technology system in Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-serpent>=1.23:../../devel/py-serpent

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

do-test:
	cd ${WRKSRC}/tests && ${PYTHONBIN} run_testsuite.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
