# $NetBSD: Makefile,v 1.6 2022/01/04 20:54:16 wiz Exp $

DISTNAME=	pymc3-3.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pymc3/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/pymc-devs/pymc3
COMMENT=	Bayesian modeling and probabilistic machine learning
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-Theano>=1.0.0:../../math/py-Theano
DEPENDS+=	${PYPKGPREFIX}-h5py>=2.7.0:../../devel/py-h5py
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=1.5.0:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.13.0:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.18.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-patsy>=0.4.0:../../math/py-patsy
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.18.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-tqdm>=4.8.4:../../misc/py-tqdm

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-matplotlib, py-scipy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
