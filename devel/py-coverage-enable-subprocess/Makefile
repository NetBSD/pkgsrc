# $NetBSD: Makefile,v 1.1 2022/05/04 12:36:42 adam Exp $

DISTNAME=	coverage_enable_subprocess-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/coverage_enable_subprocess/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bukzor/python-coverage-enable-subprocess
COMMENT=	Enable Python coverage for subprocesses
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

USE_LANGUAGES=  # none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
