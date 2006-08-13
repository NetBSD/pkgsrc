# $NetBSD: Makefile,v 1.7 2006/08/13 23:32:22 wiz Exp $
#

DISTNAME=       adns-python-1.0.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=     net python
MASTER_SITES=   http://dustman.net/andy/python/adns-python/1.0.0/

MAINTAINER=     pkgsrc-users@NetBSD.org
HOMEPAGE=       http://dustman.net/andy/python/adns-python/
COMMENT=        Python interface to the GNU asynchronous DNS resolver library

PYDISTUTILSPKG=

.include "../../net/adns/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

