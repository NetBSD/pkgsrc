# $NetBSD: Makefile,v 1.27 2016/03/06 16:58:38 adam Exp $

DISTNAME=	dnspython-1.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-/-/}
CATEGORIES=	net python
MASTER_SITES=	http://www.dnspython.org/kits/${PKGVERSION}/

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.dnspython.org/
COMMENT=	Python DNS toolkit (python-2.x version)
LICENSE=	modified-bsd

USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
