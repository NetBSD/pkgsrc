# $NetBSD: Makefile,v 1.20 2022/01/10 09:06:06 wiz Exp $

DISTNAME=	ephem-3.7.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
