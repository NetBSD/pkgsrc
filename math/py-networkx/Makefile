# $NetBSD: Makefile,v 1.8 2012/09/11 23:04:31 asau Exp $
#

DISTNAME=	networkx-1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/n/networkx/ \
		http://networkx.lanl.gov/download/networkx/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://networkx.lanl.gov/
COMMENT=	Python package for creating and manipulating graphs and networks
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	25

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
