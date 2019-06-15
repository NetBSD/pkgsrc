# $NetBSD: Makefile,v 1.4 2019/06/15 18:01:47 adam Exp $

DISTNAME=	Theano-1.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=T/Theano/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://deeplearning.net/software/theano/
COMMENT=	Optimizing compiler for evaluating mathematical expressions
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.17.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.0:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-parameterized-[0-9]*:../../devel/py-parameterized

USE_TOOLS+=	bash
USE_LANGUAGES=	c c++

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	.*/bin/bash
REPLACE.bash.new=	${SH}
REPLACE_FILES.bash=	theano/misc/check_blas_many.sh

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-scipy

zz-do-test:
	cd ${WRKSRC}/theano/tests && \
	${SETENV} ${TEST_ENV} ${PYTHONBIN} main.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} theano-cache theano-cache-${PYVERSSUFFIX} && \
	${MV} theano-nose theano-nose-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
