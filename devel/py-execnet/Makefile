# $NetBSD: Makefile,v 1.8 2021/02/09 09:03:38 adam Exp $

DISTNAME=	execnet-1.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/execnet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://execnet.readthedocs.io/
COMMENT=	Rapid multi-Python deployment
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-apipkg>=1.4:../../devel/py-apipkg

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
