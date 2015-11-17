# $NetBSD: Makefile,v 1.3 2015/11/17 11:53:43 wiz Exp $

DISTNAME=	ipaddress-1.0.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES+=	${MASTER_SITE_PYPI:=i/ipaddress/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/ipaddress
COMMENT=	Port of the python 3.3+ ipaddress module to 2.6 and 2.7
LICENSE=	python-software-foundation

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # included in 3.3+

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test_ipaddress.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
