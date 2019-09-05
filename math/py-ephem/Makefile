# $NetBSD: Makefile,v 1.17 2019/09/05 10:39:50 adam Exp $

DISTNAME=	ephem-3.7.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/ephem/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rhodesmill.org/pyephem/
COMMENT=	Scientific-grade astronomical computations for Python
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v3

REPLACE_PYTHON+=	ephem/tests/test_*.py

do-test:
	cd ${WRKSRC}/ephem && ${PYTHONBIN} -m unittest discover

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
