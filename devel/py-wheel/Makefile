# $NetBSD: Makefile,v 1.7 2018/04/05 11:51:07 adam Exp $

DISTNAME=	wheel-0.31.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wheel/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://bitbucket.org/pypa/wheel/
COMMENT=	Built-package format for Python
LICENSE=	mit

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} wheel wheel-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
