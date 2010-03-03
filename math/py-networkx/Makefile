# $NetBSD: Makefile,v 1.4 2010/03/03 12:00:59 obache Exp $
#

DISTNAME=	networkx-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/n/networkx/ \
		http://networkx.lanl.gov/download/networkx/ \

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://networkx.lanl.gov/
COMMENT=	Python package for creating and manipulating graphs and networks

PKG_DESTDIR_SUPPORT=	user-destdir
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
