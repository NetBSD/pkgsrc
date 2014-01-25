# $NetBSD: Makefile,v 1.6 2014/01/25 08:44:53 wiz Exp $

DISTNAME=	pycassa-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
EGG_NAME=	${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	http://github.com/downloads/pycassa/pycassa/

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	https://github.com/pycassa/pycassa
COMMENT=	Python client library for Cassandra

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	33

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
