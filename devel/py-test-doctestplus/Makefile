# $NetBSD: Makefile,v 1.2 2023/05/29 12:15:08 adam Exp $

DISTNAME=	pytest-doctestplus-0.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-doctestplus/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://astropy.org/
COMMENT=	Pytest plugin with advanced doctest features
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-packaging>=17.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-test>=4.6:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
