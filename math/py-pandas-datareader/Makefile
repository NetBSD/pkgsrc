# $NetBSD: Makefile,v 1.1 2017/07/05 19:17:56 minskim Exp $

DISTNAME=	pandas-datareader-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pandas-datareader/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://pandas.pydata.org/
COMMENT=	Remote data access for pandas
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-requests>=2.3.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-ftp-[0-9]*:../../devel/py-requests-ftp
DEPENDS+=	${PYPKGPREFIX}-requests-file-[0-9]*:../../devel/py-requests-file
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.17.0:../../math/py-pandas

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
