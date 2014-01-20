# $NetBSD: Makefile,v 1.2 2014/01/20 11:10:04 wiz Exp $

DISTNAME=	dnspython3-1.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python3-/-/}
CATEGORIES=	net python
MASTER_SITES=	http://www.dnspython.org/kits3/${PKGVERSION}/

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.dnspython.org/
COMMENT=	Python DNS toolkit (python-3.x version)
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	26 27
PYTHON_VERSIONS_INCLUDE_3X=	yes

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
