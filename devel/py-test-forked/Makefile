# $NetBSD: Makefile,v 1.9 2022/01/13 19:31:22 wiz Exp $

DISTNAME=	pytest-forked-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-forked/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-forked
COMMENT=	Run tests in isolated forked subprocesses
LICENSE=	mit

PYTHON_VERSIONED_DEPENDENCIES=	test setuptools_scm:build

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} testing

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
