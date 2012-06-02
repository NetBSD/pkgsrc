# $NetBSD: Makefile,v 1.6 2012/06/02 13:19:17 obache Exp $
#

DISTNAME=	networkx-1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/n/networkx/ \
		http://networkx.lanl.gov/download/networkx/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://networkx.lanl.gov/
COMMENT=	Python package for creating and manipulating graphs and networks
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCOMPATIBLE=	25

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
