# $NetBSD: Makefile,v 1.1 2020/05/19 16:58:23 wiz Exp $

DISTNAME=	filetype-1.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_GITHUB:=h2non/}
GITHUB_PROJECT=	filetype.py
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/h2non/filetype.py/
COMMENT=	Infer binary file types checking the magic numbers signature
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark-[0-9]*:../../devel/py-test-benchmark

PYTHON_VERSIONED_DEPENDENCIES+=	test:test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} py.test-${PYVERSSUFFIX}

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
