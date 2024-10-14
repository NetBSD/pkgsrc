# $NetBSD: Makefile,v 1.3 2024/10/14 06:45:53 wiz Exp $

DISTNAME=	Theano-PyMC-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=T/Theano-PyMC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/theano-pymc
COMMENT=	Optimizing compiler for evaluating mathematical expressions
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-versioneer-[0-9]*:../../devel/py-versioneer
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-filelock-[0-9]*:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.9.1:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.14:../../math/py-scipy

PYTHON_VERSIONS_INCOMPATIBLE=	39
REPLACE_SH+=			theano/misc/check_blas_many.sh

# Prefer versioneer from pkgsrc.
post-extract:
	${RM} ${WRKSRC}/versioneer.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} theano-cache theano-cache-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
