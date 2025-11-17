# $NetBSD: Makefile,v 1.23 2025/11/17 10:07:17 wiz Exp $

DISTNAME=	cachecontrol-0.14.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/CacheControl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ionrock/cachecontrol
COMMENT=	Port of httplib2's caching to requests
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0:../../devel/py-uv-build
DEPENDS+=	${PYPKGPREFIX}-msgpack>=0.5.2:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-requests>=2.16.0:../../devel/py-requests
# optional
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.8.0:../../devel/py-filelock
TEST_DEPENDS+=	${PYPKGPREFIX}-cherrypy>=0:../../www/py-cherrypy

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} doesitcache doesitcache-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
