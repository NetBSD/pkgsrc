# $NetBSD: Makefile,v 1.5 2012/10/02 21:25:48 asau Exp $

DISTNAME=	pycassa-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
EGG_NAME=	${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	http://github.com/downloads/vomjom/pycassa/

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://github.com/vomjom/pycassa/
COMMENT=	Python client library for Cassandra

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
