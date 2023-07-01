# $NetBSD: Makefile,v 1.3 2023/07/01 08:37:34 wiz Exp $

DISTNAME=	xdist-0.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xdist/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/doerlbh/xdist
COMMENT=	Python library of pairwise distance computation
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-pandas>=0:../../math/py-pandas
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=0:../../devel/py-nose

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 38

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.16.5
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
