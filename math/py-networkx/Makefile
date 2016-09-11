# $NetBSD: Makefile,v 1.22 2016/09/11 16:55:17 wiz Exp $

DISTNAME=	networkx-1.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/networkx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://networkx.github.io/
COMMENT=	Python package for creating and manipulating graphs and networks
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-decorator>=4.0.10:../../devel/py-decorator
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.7:../../devel/py-nose

USE_LANGUAGES=	# none

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

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
