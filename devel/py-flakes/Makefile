# $NetBSD: Makefile,v 1.21 2022/01/05 15:41:04 wiz Exp $

DISTNAME=	pyflakes-2.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyflakes/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/PyCQA/pyflakes
COMMENT=	Passive checker of Python programs
LICENSE=	mit

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pyflakes pyflakes-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
