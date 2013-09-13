# $NetBSD: Makefile,v 1.1 2013/09/13 08:09:46 fhajny Exp $
#

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
DISTNAME=	pylibmc-1.2.3
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/p/pylibmc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/pylibmc
COMMENT=	Quick and small memcached client for Python
LICENSE=	modified-bsd

PYDISTUTILSPKG=	yes

.include "../../devel/libmemcached/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
