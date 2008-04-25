# $NetBSD: Makefile,v 1.2 2008/04/25 20:39:11 joerg Exp $
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
PYTHON_VERSIONS_ACCEPTED= 25 24

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
