# $NetBSD: Makefile,v 1.9 2022/05/23 11:56:16 adam Exp $

DISTNAME=	CacheControl-0.12.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/CacheControl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ionrock/cachecontrol
COMMENT=	Port of httplib2's caching to requests
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-msgpack>=0.5.2:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
# filecache
DEPENDS+=	${PYPKGPREFIX}-lockfile>=0.9:../../devel/py-lockfile

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} doesitcache doesitcache-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
