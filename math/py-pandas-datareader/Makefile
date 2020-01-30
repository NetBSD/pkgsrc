# $NetBSD: Makefile,v 1.10 2020/01/30 20:25:18 minskim Exp $

DISTNAME=	pandas-datareader-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pandas-datareader/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/pydata/pandas-datareader
COMMENT=	Remote data access for pandas
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.21:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-requests>=2.3.0:../../devel/py-requests

PYTHON_VERSIONS_INCOMPATIBLE=	27      # py-pandas

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
