# $NetBSD: Makefile,v 1.17 2023/08/01 23:20:47 wiz Exp $

DISTNAME=	pandas-datareader-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pandas-datareader/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/pydata/pandas-datareader
COMMENT=	Remote data access for pandas
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.23:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-requests>=2.19.0:../../devel/py-requests

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
