# $NetBSD: Makefile,v 1.1 2026/11/26 21:05:04 kim Exp $

DISTNAME=	shtab-1.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/shtab/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tqdm/shtab
COMMENT=	Automagic shell tab completion for Python CLI applications
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=77:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none
USE_TOOLS+=	bash:test

PY_RENAME_BINARIES=	shtab

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
