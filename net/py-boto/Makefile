# $NetBSD: Makefile,v 1.6 2011/01/01 17:51:06 gson Exp $
#

DISTNAME=	boto-1.9b
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://boto.googlecode.com/files/

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://boto.googlecode.com/
COMMENT=	Python interface to Amazon web services

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= 	yes
PYTHON_VERSIONS_ACCEPTED= 26 25 24

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
