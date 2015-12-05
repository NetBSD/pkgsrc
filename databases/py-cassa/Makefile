# $NetBSD: Makefile,v 1.9 2015/12/05 21:25:32 adam Exp $

DISTNAME=	pycassa-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	databases python
MASTER_SITES=	http://github.com/downloads/pycassa/pycassa/

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	https://github.com/pycassa/pycassa
COMMENT=	Python client library for Cassandra

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
