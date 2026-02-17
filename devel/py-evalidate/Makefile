# $NetBSD: Makefile,v 1.1 2026/02/17 22:04:32 wiz Exp $

DISTNAME=	evalidate-2.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/evalidate/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yaroslaff/evalidate
COMMENT=	Validation and secure evaluation of untrusted python expressions
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	evalidate/__init__.py
REPLACE_PYTHON+=	evalidate/cli/jg.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} genfakeproducts genfakeproducts-${PYVERSSUFFIX} || ${TRUE}
	cd ${DESTDIR}${PREFIX}/bin && ${MV} jg jg-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
