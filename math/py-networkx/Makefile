# $NetBSD: Makefile,v 1.28 2019/06/17 14:58:26 adam Exp $

DISTNAME=	networkx-2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/networkx/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://networkx.github.io/
COMMENT=	Python package for creating and manipulating graphs and networks
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-decorator>=4.3.0:../../devel/py-decorator
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.7:../../devel/py-nose

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
