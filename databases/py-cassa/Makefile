# $NetBSD: Makefile,v 1.8 2014/12/31 13:57:25 wiz Exp $

DISTNAME=	pycassa-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	databases python
MASTER_SITES=	http://github.com/downloads/pycassa/pycassa/

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	https://github.com/pycassa/pycassa
COMMENT=	Python client library for Cassandra

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
