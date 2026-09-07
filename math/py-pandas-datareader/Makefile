# $NetBSD: Makefile,v 1.25 2026/09/07 16:26:12 adam Exp $

DISTNAME=	pandas_datareader-0.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pandas-datareader/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/pydata/pandas-datareader
COMMENT=	Remote data access for pandas
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-lxml>=0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-pandas>=2.1.4:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-requests>=2.19.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
