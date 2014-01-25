# $NetBSD: Makefile,v 1.24 2014/01/25 09:09:06 wiz Exp $

DISTNAME=	dnspython-1.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-/-/}
CATEGORIES=	net python
MASTER_SITES=	http://www.dnspython.org/kits/${PKGVERSION}/

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.dnspython.org/
COMMENT=	Python DNS toolkit (python-2.x version)
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	33

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
