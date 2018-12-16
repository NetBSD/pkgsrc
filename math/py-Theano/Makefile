# $NetBSD: Makefile,v 1.3 2018/12/16 14:54:39 adam Exp $

DISTNAME=	Theano-1.0.3
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

do-test:
	${RUN} cd ${WRKSRC}/theano/tests && \
		${SETENV} ${TEST_ENV} ${PYTHONBIN} main.py

post-install:
.for cmd in theano-cache theano-nose
	${MV} ${DESTDIR}${PREFIX}/bin/${cmd} \
		${DESTDIR}${PREFIX}/bin/${cmd}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
