# $NetBSD: Makefile,v 1.26 2018/05/07 15:27:09 khorben Exp $

DISTNAME=	networkx-2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/networkx/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://networkx.github.io/
COMMENT=	Python package for creating and manipulating graphs and networks
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-decorator>=4.1.0:../../devel/py-decorator

USE_LANGUAGES=	# none

REPLACE_INTERPRETER+=	python
REPLACE.python.old=	/usr/bin/env python
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	\
examples/drawing/*.py \
examples/advanced/*.py \
examples/graph/*.py \
examples/applications/*.py \
examples/algorithms/*.py \
examples/pygraphviz/*.py \
examples/basic/*.py \
examples/jit/*.py \
doc/release/*.py \
networkx/readwrite/tests/*.py \
networkx/utils/tests/*.py \
networkx/generators/tests/*.py \
networkx/classes/tests/*.py \
networkx/algorithms/components/tests/*.py \
networkx/algorithms/isomorphism/tests/*.py \
networkx/algorithms/link_analysis/tests/*.py \
networkx/algorithms/centrality/tests/*.py \
networkx/algorithms/bipartite/tests/*.py \
networkx/algorithms/traversal/tests/*.py \
networkx/algorithms/approximation/tests/*.py \
networkx/algorithms/assortativity/tests/*.py \
networkx/algorithms/shortest_paths/tests/*.py \
networkx/algorithms/tests/*.py \
networkx/tests/*.py

post-install:
	${RM} -f -r ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${MV} ${DESTDIR}${PREFIX}/share/doc/${DISTNAME} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
