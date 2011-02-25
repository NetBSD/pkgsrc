# $NetBSD: Makefile,v 1.3 2011/02/25 09:47:19 wiz Exp $

DISTNAME=	pycassa-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
EGG_NAME=	${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	http://github.com/downloads/vomjom/pycassa/

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://github.com/vomjom/pycassa/
COMMENT=	Python client library for Cassandra

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED= 27 26 25
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
