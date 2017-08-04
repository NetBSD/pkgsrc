# $NetBSD: Makefile,v 1.11 2017/08/04 05:01:57 adam Exp $

DISTNAME=	pyflakes-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyflakes/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/PyCQA/pyflakes
COMMENT=	Passive checker of Python programs
LICENSE=	mit

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pyflakes pyflakes${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
