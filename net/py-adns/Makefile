# $NetBSD: Makefile,v 1.3 2004/07/22 09:16:03 recht Exp $
#

DISTNAME=       adns-python-1.0.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=     net python
MASTER_SITES=   http://dustman.net/andy/python/adns-python/1.0.0/

MAINTAINER=     adam@monkeybyte.org
HOMEPAGE=       http://dustman.net/andy/python/adns-python/
COMMENT=        Python interface to the GNU asynchronous DNS resolver library

PYDISTUTILSPKG=
USE_BUILDLINK3= yes

.include "../../net/adns/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

