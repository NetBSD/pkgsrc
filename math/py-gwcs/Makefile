# $NetBSD: Makefile,v 1.6 2023/08/01 23:20:46 wiz Exp $

DISTNAME=	gwcs-0.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gwcs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gwcs.readthedocs.io/en/latest/
COMMENT=	Generalized World Coordinate System
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=1.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-astropy>=4.2:../../math/py-astropy
DEPENDS+=	${PYPKGPREFIX}-asdf>=2.7.1:../../math/py-asdf

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
