# $NetBSD: Makefile,v 1.2 2026/03/04 13:44:15 adam Exp $

DISTNAME=	evalidate-2.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/evalidate/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yaroslaff/evalidate
COMMENT=	Validation and secure evaluation of untrusted python expressions
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=>=1.27.0:../../devel/py-hatchling

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	evalidate/__init__.py
REPLACE_PYTHON+=	evalidate/cli/jg.py

post-install:
.for bin in genfakeproducts jg
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
