# $NetBSD: Makefile,v 1.3 2024/04/30 14:04:38 wiz Exp $

DISTNAME=	coverage_enable_subprocess-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/coverage_enable_subprocess/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bukzor/python-coverage-enable-subprocess
COMMENT=	Enable Python coverage for subprocesses
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
