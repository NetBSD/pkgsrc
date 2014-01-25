# $NetBSD: Makefile,v 1.12 2014/01/25 10:30:13 wiz Exp $

DISTNAME=	networkx-1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/n/networkx/ \
		http://networkx.lanl.gov/download/networkx/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://networkx.lanl.gov/
COMMENT=	Python package for creating and manipulating graphs and networks
LICENSE=	modified-bsd

PYTHON_SELF_CONFLICT=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
