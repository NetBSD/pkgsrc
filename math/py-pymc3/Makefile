# $NetBSD: Makefile,v 1.1 2018/07/06 03:46:43 minskim Exp $

DISTNAME=	pymc3-3.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pymc3/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/pymc-devs/pymc3
COMMENT=	Bayesian modeling and probabilistic machine learning
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-h5py>=2.7.0:../../devel/py-h5py
DEPENDS+=	${PYPKGPREFIX}-joblib>=0.9:../../devel/py-joblib
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=1.5.0:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.18.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-patsy>=0.4.0:../../math/py-patsy
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-Theano>=1.0.0:../../math/py-Theano
DEPENDS+=	${PYPKGPREFIX}-tqdm>=4.8.4:../../misc/py-tqdm

.include "../../lang/python/pyversion.mk"
.if "${PYPKGPREFIX}" == "py27"
DEPENDS+=	${PYPKGPREFIX}-enum34>=1.1.6:../../devel/py-enum34
.endif

.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.13.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
