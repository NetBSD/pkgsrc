# $NetBSD: Makefile,v 1.13 2022/01/04 20:54:28 wiz Exp $

DISTNAME=	ipaddress-1.0.23
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net devel python
MASTER_SITES+=	${MASTER_SITE_PYPI:=i/ipaddress/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/ipaddress
COMMENT=	Port of the python 3.3+ ipaddress module to 2.6 and 2.7
LICENSE=	python-software-foundation

PYTHON_VERSIONS_ACCEPTED=	27 # included in 3.3+

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test_ipaddress.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
