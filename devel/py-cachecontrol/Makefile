# $NetBSD: Makefile,v 1.10 2023/05/30 07:39:18 wiz Exp $

DISTNAME=	CacheControl-0.12.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/CacheControl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ionrock/cachecontrol
COMMENT=	Port of httplib2's caching to requests
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-msgpack>=0.5.2:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
# filecache
DEPENDS+=	${PYPKGPREFIX}-filelock>=0:../../devel/py-filelock
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-cherrypy>=0:../../www/py-cherrypy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} doesitcache doesitcache-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
