# $NetBSD: Makefile,v 1.2 2022/08/24 09:25:55 wiz Exp $

DISTNAME=	coverage_enable_subprocess-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/coverage_enable_subprocess/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bukzor/python-coverage-enable-subprocess
COMMENT=	Enable Python coverage for subprocesses
LICENSE=	mit

PYTHON_VERSIONED_DEPENDENCIES+=	coverage

USE_LANGUAGES=  # none

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
