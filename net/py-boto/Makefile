# $NetBSD: Makefile,v 1.1.1.1 2008/02/06 07:08:11 bjs Exp $
#

DISTNAME=	boto-1.0a
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://boto.googlecode.com/files/

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://boto.googlecode.com/
COMMENT=	Python interface to Amazon web services

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= 	yes
PYTHON_VERSIONS_ACCEPTED= 24

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
