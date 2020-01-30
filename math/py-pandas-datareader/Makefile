# $NetBSD: Makefile,v 1.9 2020/01/30 18:45:28 minskim Exp $

DISTNAME=	pandas-datareader-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pandas-datareader/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/pydata/pandas-datareader
COMMENT=	Remote data access for pandas
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pandas>=0.19.2:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-requests>=2.3.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-file-[0-9]*:../../devel/py-requests-file
DEPENDS+=	${PYPKGPREFIX}-requests-ftp-[0-9]*:../../devel/py-requests-ftp

PYTHON_VERSIONS_INCOMPATIBLE=	27      # py-pandas

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
