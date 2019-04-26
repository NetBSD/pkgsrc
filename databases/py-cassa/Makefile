# $NetBSD: Makefile,v 1.14 2019/04/26 13:13:46 maya Exp $

DISTNAME=	pycassa-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	databases python
MASTER_SITES=	http://github.com/downloads/pycassa/pycassa/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pycassa/pycassa
COMMENT=	Python client library for Cassandra

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	 36 37

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
