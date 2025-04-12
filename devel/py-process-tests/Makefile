# $NetBSD: Makefile,v 1.4 2025/04/12 11:55:00 adam Exp $

DISTNAME=	process-tests-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/process-tests/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ionelmc/python-process-tests
COMMENT=	Tools for testing processes
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

SUBST_CLASSES+=		pypath
SUBST_STAGE.pypath=	pre-configure
SUBST_MESSAGE.pypath=	Fixing command path in tests.
SUBST_FILES.pypath=	tests/test_process_tests.py
SUBST_SED.pypath=	-e "s,'python','${PYTHONBIN}',g"

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
