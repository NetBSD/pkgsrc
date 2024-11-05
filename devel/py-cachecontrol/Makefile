# $NetBSD: Makefile,v 1.18 2024/11/05 09:06:11 adam Exp $

DISTNAME=	cachecontrol-0.14.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/CacheControl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ionrock/cachecontrol
COMMENT=	Port of httplib2's caching to requests
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.2:../../devel/py-flit_core
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
