# $NetBSD: Makefile,v 1.8 2007/02/22 19:26:58 wiz Exp $
#

DISTNAME=	adns-python-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	http://dustman.net/andy/python/adns-python/1.0.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dustman.net/andy/python/adns-python/
COMMENT=	Python interface to the GNU asynchronous DNS resolver library

PYDISTUTILSPKG=

.include "../../net/adns/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

