# $NetBSD: Makefile,v 1.11 2024/10/14 06:45:51 wiz Exp $

DISTNAME=	pymc3-3.11.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pymc3/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/pymc-devs/pymc3
COMMENT=	Bayesian modeling and probabilistic machine learning
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-arviz>=0.11.0:../../math/py-arviz
DEPENDS+=	${PYPKGPREFIX}-cachetools>=4.2.1:../../devel/py-cachetools
DEPENDS+=	${PYPKGPREFIX}-deprecat>0:../../devel/py-deprecat
DEPENDS+=	${PYPKGPREFIX}-dill>0:../../textproc/py-dill
DEPENDS+=	${PYPKGPREFIX}-fastprogress>=0.2.0:../../misc/py-fastprogress
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.15.0:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.24.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-patsy>=0.5.1:../../math/py-patsy
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.7.3:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-semver>=2.13.0:../../devel/py-semver
DEPENDS+=	${PYPKGPREFIX}-theano-pymc>=1.1.2:../../math/py-theano-pymc
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4:../../devel/py-typing-extensions

PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
