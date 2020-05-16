# $NetBSD: Makefile,v 1.3 2020/05/16 16:30:16 adam Exp $

DISTNAME=	pytest-pythonpath-0.7.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-pythonpath/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bigsassy/pytest-pythonpath
COMMENT=	Pytest plugin for adding to the PYTHONPATH
LICENSE=	mit

PYTHON_VERSIONED_DEPENDENCIES=	test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
