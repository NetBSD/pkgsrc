# $NetBSD: Makefile,v 1.5 2016/03/06 16:58:38 adam Exp $

DISTNAME=	dnspython3-1.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python3-/-/}
CATEGORIES=	net python
MASTER_SITES=	http://www.dnspython.org/kits3/${PKGVERSION}/

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.dnspython.org/
COMMENT=	Python DNS toolkit (python-3.x version)
LICENSE=	modified-bsd

USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
