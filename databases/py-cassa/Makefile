# $NetBSD: Makefile,v 1.4 2012/04/08 19:08:47 wiz Exp $

DISTNAME=	pycassa-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
EGG_NAME=	${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	http://github.com/downloads/vomjom/pycassa/

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://github.com/vomjom/pycassa/
COMMENT=	Python client library for Cassandra

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
