# $NetBSD: Makefile,v 1.4 2021/01/10 21:49:59 adam Exp $

DISTNAME=	pytest-rerunfailures-9.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-rerunfailures/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-rerunfailures
COMMENT=	Pytest plugin to re-run tests to eliminate flaky failures
LICENSE=	mpl-2.0

DEPENDS+=	${PYPKGPREFIX}-test>=5.0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
