# $NetBSD: Makefile,v 1.2 2021/10/01 12:48:28 adam Exp $

DISTNAME=	filetype-1.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/filetype/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/h2non/filetype.py
COMMENT=	Infer binary file types checking the magic numbers signature
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark-[0-9]*:../../devel/py-test-benchmark

PYTHON_VERSIONED_DEPENDENCIES+=	test:test

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} filetype filetype-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
