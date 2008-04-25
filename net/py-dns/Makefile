# $NetBSD: Makefile,v 1.15 2008/04/25 19:32:44 tnn Exp $

DISTNAME=	dnspython-1.6.0
PKGNAME=	${PYPKGPREFIX}-dns-1.6.0
CATEGORIES=	net python
MASTER_SITES=	http://www.dnspython.org/kits/${PKGVERSION}/

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.dnspython.org/
COMMENT=	Python DNS toolkit

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

PYTHON_VERSIONS_ACCEPTED=	25 24 23

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
