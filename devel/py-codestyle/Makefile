# $NetBSD: Makefile,v 1.17 2024/11/11 07:28:03 wiz Exp $

DISTNAME=	pycodestyle-2.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycodestyle/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	https://github.com/PyCQA/pycodestyle
COMMENT=	Python style guide checker
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pycodestyle pycodestyle-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
