# $NetBSD: Makefile,v 1.25 2024/11/11 07:28:08 wiz Exp $

DISTNAME=	pyflakes-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyflakes/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/PyCQA/pyflakes
COMMENT=	Passive checker of Python programs
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pyflakes pyflakes-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
