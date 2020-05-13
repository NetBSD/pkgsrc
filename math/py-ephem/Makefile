# $NetBSD: Makefile,v 1.19 2020/05/13 14:53:29 adam Exp $

DISTNAME=	ephem-3.7.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/ephem/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rhodesmill.org/pyephem/
COMMENT=	Scientific-grade astronomical computations for Python
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v3

REPLACE_PYTHON+=	ephem/tests/test_*.py

do-test:
	cd ${WRKSRC}/ephem && ${PYTHONBIN} -m unittest discover

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
