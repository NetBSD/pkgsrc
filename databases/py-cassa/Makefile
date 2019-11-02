# $NetBSD: Makefile,v 1.16 2019/11/02 15:38:09 rillig Exp $

DISTNAME=	pycassa-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	databases python
MASTER_SITES=	http://github.com/downloads/pycassa/pycassa/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pycassa/pycassa
COMMENT=	Python client library for Cassandra

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED= 27

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
