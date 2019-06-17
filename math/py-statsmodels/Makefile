# $NetBSD: Makefile,v 1.4 2019/06/17 05:29:43 adam Exp $

DISTNAME=	statsmodels-0.9.0
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/statsmodels/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.statsmodels.org/stable/index.html
COMMENT=	Statistical computations and models for use with SciPy
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cython>=0.14.1:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.14.1:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-patsy>=0.3.0:../../math/py-patsy
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.0:../../math/py-scipy

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-matplotlib, py-scipy

SUBST_CLASSES+=		scipy
SUBST_STAGE.scipy=	pre-configure
SUBST_MESSAGE.scipy=	Fix for newer SciPy
SUBST_FILES.scipy=	statsmodels/distributions/edgeworth.py
SUBST_FILES.scipy+=	statsmodels/distributions/tests/test_edgeworth.py
SUBST_FILES.scipy+=	statsmodels/graphics/functional.py
SUBST_FILES.scipy+=	statsmodels/miscmodels/count.py
SUBST_FILES.scipy+=	statsmodels/sandbox/distributions/genpareto.py
SUBST_FILES.scipy+=	statsmodels/sandbox/infotheo.py
SUBST_FILES.scipy+=	statsmodels/sandbox/nonparametric/densityorthopoly.py
SUBST_FILES.scipy+=	statsmodels/sandbox/nonparametric/kernels.py
SUBST_FILES.scipy+=	statsmodels/sandbox/stats/runs.py
SUBST_FILES.scipy+=	statsmodels/stats/moment_helpers.py
SUBST_FILES.scipy+=	statsmodels/tsa/regime_switching/markov_switching.py
SUBST_SED.scipy=	-e 's,\(from scipy\).misc,\1.special,'

.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=0.12.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
