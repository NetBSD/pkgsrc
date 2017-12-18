# $NetBSD: Makefile,v 1.4 2017/12/18 08:48:26 adam Exp $

DISTNAME=	stevedore-1.28.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stevedore/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/dreamhost/stevedore
COMMENT=	Manage dynamic plugins for Python applications
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-pbr>=2.1.1:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
# test
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock>=2.0.0:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-coverage>=4.4.1:../../devel/py-coverage
testrepository>=0.0.18
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.6.2:../../textproc/py-sphinx
bandit>=1.1.0

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
