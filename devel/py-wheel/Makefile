# $NetBSD: Makefile,v 1.13 2019/02/15 12:55:38 adam Exp $

DISTNAME=	wheel-0.33.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wheel/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pypa/wheel
COMMENT=	Built-package format for Python
LICENSE=	mit

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} wheel wheel-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
