# $NetBSD: Makefile,v 1.19 2025/07/01 19:31:43 wiz Exp $

DISTNAME=	pycodestyle-2.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycodestyle/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	https://pycodestyle.pycqa.org/en/latest/
COMMENT=	Python style guide checker
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pycodestyle pycodestyle-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
