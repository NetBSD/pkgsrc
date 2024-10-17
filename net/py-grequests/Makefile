# $NetBSD: Makefile,v 1.2 2024/10/17 20:55:01 wiz Exp $

DISTNAME=	grequests-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/grequests/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/spyoungtech/grequests
COMMENT=	Requests + Gevent
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-gevent>=0:../../net/py-gevent
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
# tests not included
#TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=0:../../devel/py-nose

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
