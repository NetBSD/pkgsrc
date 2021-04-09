# $NetBSD: Makefile,v 1.6 2021/04/09 14:41:34 tnn Exp $

DISTNAME=	seaborn-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/seaborn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://seaborn.pydata.org/
COMMENT=	Statistical data visualization
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-matplotlib>=1.4.3:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.9.3:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.15.2:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.14.0:../../math/py-scipy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	36 27	# py-matplotlib, py-scipy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
