# $NetBSD: Makefile,v 1.2 2018/09/27 23:50:54 tnn Exp $

DISTNAME=	Theano-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_GITHUB:=Theano/}
GITHUB_PROJECT=	Theano
GITHUB_TAG=	rel-${PKGVERSION_NOREV}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://deeplearning.net/software/theano/
COMMENT=	Optimizing compiler for evaluating mathematical expressions
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.7:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.17.0:../../math/py-scipy

USE_TOOLS+=	bash
USE_LANGUAGES=	c c++

PY_PATCHPLIST=	yes

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	.*/bin/bash
REPLACE.bash.new=	${SH}
REPLACE_FILES.bash=	theano/misc/check_blas_many.sh

do-test:
	${RUN} cd {WRKSRC}/theano/tests && \
		${SETENV} {TEST_ENV} ${PYTHONBIN} main.py

post-install:
.for cmd in theano-cache theano-nose
	${MV} ${DESTDIR}${PREFIX}/bin/${cmd} \
		${DESTDIR}${PREFIX}/bin/${cmd}${PYVERSSUFFIX}
.endfor

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
