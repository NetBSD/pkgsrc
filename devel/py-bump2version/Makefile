# $NetBSD: Makefile,v 1.3 2020/10/09 03:33:09 gutteridge Exp $

DISTNAME=	bump2version-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bump2version/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/c4urself/bump2version
COMMENT=	Version-bump software with a single command
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/bumpversion ${DESTDIR}${PREFIX}/bin/bumpversion-${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/bump2version ${DESTDIR}${PREFIX}/bin/bump2version-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
