# $NetBSD: Makefile,v 1.2 2019/12/16 10:25:11 adam Exp $

DISTNAME=	pytest-rerunfailures-8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-rerunfailures/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-rerunfailures
COMMENT=	Pytest plugin to re-run tests to eliminate flaky failures
LICENSE=	mpl-2.0

DEPENDS+=	${PYPKGPREFIX}-test>=3.10:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
