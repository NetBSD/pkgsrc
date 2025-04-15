# $NetBSD: Makefile,v 1.21 2025/04/15 16:31:38 adam Exp $

DISTNAME=	pandas-datareader-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pandas-datareader/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/pydata/pandas-datareader
COMMENT=	Remote data access for pandas
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.23:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-requests>=2.19.0:../../devel/py-requests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
