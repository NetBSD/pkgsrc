# $NetBSD: Makefile,v 1.1.1.1 2003/07/25 11:49:53 drochner Exp $
#

DISTNAME=       adns-python-1.0.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=     net
MASTER_SITES=   http://dustman.net/andy/python/adns-python/1.0.0/

MAINTAINER=     adam@monkeybyte.org
HOMEPAGE=       http://dustman.net/andy/python/adns-python/
COMMENT=        Python interface to the GNU asynchronous DNS resolver library

PYDISTUTILSPKG=
USE_BUILDLINK2= yes

.include "../../net/adns/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

