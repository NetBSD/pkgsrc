# $NetBSD: Makefile,v 1.2 2016/08/28 15:48:31 wiz Exp $

DISTNAME=	wheel-0.26.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wheel/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://bitbucket.org/pypa/wheel/
COMMENT=	Built-package format for Python
LICENSE=	mit

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/wheel \
	      ${DESTDIR}${PREFIX}/bin/wheel-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
