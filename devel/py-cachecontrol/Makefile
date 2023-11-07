# $NetBSD: Makefile,v 1.15 2023/11/07 22:37:58 wiz Exp $

DISTNAME=	cachecontrol-0.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/CacheControl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ionrock/cachecontrol
COMMENT=	Port of httplib2's caching to requests
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.2:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-msgpack>=0.5.2:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-requests>=2.16.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.8.0:../../devel/py-filelock
TEST_DEPENDS+=	${PYPKGPREFIX}-cherrypy>=0:../../www/py-cherrypy
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} doesitcache doesitcache-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
