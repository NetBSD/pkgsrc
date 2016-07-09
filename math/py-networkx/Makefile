# $NetBSD: Makefile,v 1.20 2016/07/09 13:03:55 wiz Exp $

DISTNAME=	networkx-1.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/networkx/} \
		http://networkx.lanl.gov/download/networkx/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://networkx.lanl.gov/
COMMENT=	Python package for creating and manipulating graphs and networks
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-decorator>=3.4.0:../../devel/py-decorator
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.7:../../devel/py-nose

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35

SUBST_CLASSES+=		python
SUBST_STAGE.python=	post-patch
SUBST_FILES.python+=	networkx/readwrite/tests/*.py
SUBST_FILES.python+=	networkx/utils/tests/*.py
SUBST_FILES.python+=	networkx/tests/*.py
SUBST_FILES.python+=	networkx/generators/tests/*.py
SUBST_FILES.python+=	networkx/classes/tests/*.py
SUBST_FILES.python+=	networkx/algorithms/tests/*.py
SUBST_FILES.python+=	networkx/algorithms/approximation/tests/*.py
SUBST_FILES.python+=	networkx/algorithms/assortativity/tests/*.py
SUBST_FILES.python+=	networkx/algorithms/bipartite/tests/*.py
SUBST_FILES.python+=	networkx/algorithms/centrality/tests/*.py
SUBST_FILES.python+=	networkx/algorithms/chordal/tests/*.py
SUBST_FILES.python+=	networkx/algorithms/community/tests/*.py
SUBST_FILES.python+=	networkx/algorithms/components/tests/*.py
SUBST_FILES.python+=	networkx/algorithms/isomorphism/tests/*.py
SUBST_FILES.python+=	networkx/algorithms/link_analysis/tests/*.py
SUBST_FILES.python+=	networkx/algorithms/shortest_paths/tests/*.py
SUBST_FILES.python+=	networkx/algorithms/traversal/tests/*.py
SUBST_MESSAGE.python=	Fixing path to Python interpreter.
SUBST_SED.python=	-e "s,/usr/bin/env python,${PYTHONBIN},g"

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
