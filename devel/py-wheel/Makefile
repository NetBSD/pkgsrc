# $NetBSD: Makefile,v 1.11 2018/10/23 07:46:04 adam Exp $

DISTNAME=	wheel-0.32.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wheel/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pypa/wheel
COMMENT=	Built-package format for Python
LICENSE=	mit

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} wheel wheel-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
