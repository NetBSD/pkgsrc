# $NetBSD: Makefile,v 1.5 2021/04/09 14:41:34 tnn Exp $

DISTNAME=	abcpmc-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/abcpmc/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.cosmology.ethz.ch/research/software-lab/abcpmc.html
COMMENT=	Approximate Bayesian Computation Population Monte Carlo
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15:../../math/py-scipy

TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=2.3:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	36 27	# py-scipy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
