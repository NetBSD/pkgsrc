# $NetBSD: Makefile,v 1.1 2008/08/27 18:53:42 apb Exp $
#

DISTNAME=	networkx-0.37
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://networkx.lanl.gov/download/networkx/ \
		http://cheeseshop.python.org/pypi/networkx/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://networkx.lanl.gov/
COMMENT=	Python package for creating and manipulating graphs and networks

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
