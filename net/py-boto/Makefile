# $NetBSD: Makefile,v 1.9 2011/07/03 10:01:04 dholland Exp $
#

DISTNAME=	boto-1.9b
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://boto.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://boto.googlecode.com/
COMMENT=	Python interface to Amazon web services

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= 	yes
PYTHON_VERSIONS_ACCEPTED= 27 26 25 24

REPLACE_PYTHON+=	boto/*/*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
