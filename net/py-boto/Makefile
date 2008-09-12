# $NetBSD: Makefile,v 1.4 2008/09/12 05:32:37 epg Exp $
#

DISTNAME=	boto-1.3a
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
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
