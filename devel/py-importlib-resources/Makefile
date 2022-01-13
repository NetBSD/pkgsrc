# $NetBSD: Makefile,v 1.10 2022/01/13 19:31:23 wiz Exp $

DISTNAME=	importlib_resources-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/importlib_resources/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://importlib-resources.readthedocs.io/
COMMENT=	Read resources from Python packages
LICENSE=	apache-2.0

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-contextlib2-[0-9]*:../../devel/py-contextlib2
DEPENDS+=	${PYPKGPREFIX}-pathlib2-[0-9]*:../../devel/py-pathlib2
DEPENDS+=	${PYPKGPREFIX}-singledispatch-[0-9]*:../../devel/py-singledispatch
DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing
.endif
.if ${_PYTHON_VERSION} < 38
PYTHON_VERSIONED_DEPENDENCIES+=	zipp
.endif
PYTHON_VERSIONED_DEPENDENCIES+=	setuptools_scm

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
