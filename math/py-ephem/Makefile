# $NetBSD: Makefile,v 1.18 2020/01/26 17:31:39 rillig Exp $

DISTNAME=	ephem-3.7.7.0
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
