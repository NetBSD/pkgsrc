# $NetBSD: Makefile,v 1.2 2020/05/16 17:13:41 adam Exp $

DISTNAME=	func_timeout-4.3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/func_timeout/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kata198/func_timeout
COMMENT=	Specify timeouts when calling any existing function
LICENSE=	gnu-lgpl-v2

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_LANGUAGES=	# none

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
