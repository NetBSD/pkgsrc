# $NetBSD: Makefile,v 1.5 2010/08/27 03:09:18 gls Exp $
#

DISTNAME=	networkx-1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/n/networkx/ \
		http://networkx.lanl.gov/download/networkx/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://networkx.lanl.gov/
COMMENT=	Python package for creating and manipulating graphs and networks
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
