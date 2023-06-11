# $NetBSD: Makefile,v 1.1 2023/06/11 08:10:26 wiz Exp $

DISTNAME=	grequests-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/grequests/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/spyoungtech/grequests
COMMENT=	Requests + Gevent
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-gevent>=0:../../net/py-gevent
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=0:../../devel/py-nose

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
