# $NetBSD: Makefile,v 1.5 2005/04/11 21:46:58 tv Exp $
#

DISTNAME=       adns-python-1.0.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=     net python
MASTER_SITES=   http://dustman.net/andy/python/adns-python/1.0.0/

MAINTAINER=     adam@monkeybyte.org
HOMEPAGE=       http://dustman.net/andy/python/adns-python/
COMMENT=        Python interface to the GNU asynchronous DNS resolver library

PYDISTUTILSPKG=

.include "../../net/adns/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

