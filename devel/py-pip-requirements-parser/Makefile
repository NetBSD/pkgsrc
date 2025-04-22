# $NetBSD: Makefile,v 1.4 2025/04/22 20:08:30 wiz Exp $

DISTNAME=	pip-requirements-parser-32.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pip-requirements-parser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nexB/pip-requirements-parser
COMMENT=	pip requirements parsing library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging

USE_LANGUAGES=	# none

# as of 32.0.1
# 5 failed, 8265 passed, 5 skipped, 1 xfailed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
