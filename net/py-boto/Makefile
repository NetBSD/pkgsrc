# $NetBSD: Makefile,v 1.8 2011/02/28 14:52:59 wiz Exp $
#

DISTNAME=	boto-1.9b
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://boto.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://boto.googlecode.com/
COMMENT=	Python interface to Amazon web services

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= 	yes
PYTHON_VERSIONS_ACCEPTED= 27 26 25 24

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
