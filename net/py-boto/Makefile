# $NetBSD: Makefile,v 1.7 2011/02/25 09:47:27 wiz Exp $
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
PYTHON_VERSIONS_ACCEPTED= 27 26 25 24

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
