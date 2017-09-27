# $NetBSD: Makefile,v 1.23 2017/09/27 13:25:54 adam Exp $

DISTNAME=	networkx-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/networkx/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://networkx.github.io/
COMMENT=	Python package for creating and manipulating graphs and networks
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-decorator>=4.1.0:../../devel/py-decorator

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	networkx/algorithms/approximation/tests/*.py
REPLACE_PYTHON+=	networkx/algorithms/assortativity/tests/*.py
REPLACE_PYTHON+=	networkx/algorithms/bipartite/tests/*.py
REPLACE_PYTHON+=	networkx/algorithms/centrality/tests/*.py
REPLACE_PYTHON+=	networkx/algorithms/chordal/tests/*.py
REPLACE_PYTHON+=	networkx/algorithms/community/tests/*.py
REPLACE_PYTHON+=	networkx/algorithms/components/tests/*.py
REPLACE_PYTHON+=	networkx/algorithms/isomorphism/tests/*.py
REPLACE_PYTHON+=	networkx/algorithms/link_analysis/tests/*.py
REPLACE_PYTHON+=	networkx/algorithms/shortest_paths/tests/*.py
REPLACE_PYTHON+=	networkx/algorithms/tests/*.py
REPLACE_PYTHON+=	networkx/algorithms/traversal/tests/*.py
REPLACE_PYTHON+=	networkx/classes/tests/*.py
REPLACE_PYTHON+=	networkx/generators/tests/*.py
REPLACE_PYTHON+=	networkx/readwrite/tests/*.py
REPLACE_PYTHON+=	networkx/tests/*.py
REPLACE_PYTHON+=	networkx/utils/tests/*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
