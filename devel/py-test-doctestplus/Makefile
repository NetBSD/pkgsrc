# $NetBSD: Makefile,v 1.1 2022/01/17 09:35:59 wiz Exp $

DISTNAME=	pytest-doctestplus-0.11.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-doctestplus/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://astropy.org/
COMMENT=	Pytest plugin with advanced doctest features
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
