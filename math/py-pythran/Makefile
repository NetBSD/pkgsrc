# $NetBSD: Makefile,v 1.30 2026/10/16 19:44:05 adam Exp $

DISTNAME=	pythran-0.19.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pythran/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pythran.readthedocs.io/
COMMENT=	Ahead of Time compiler for numeric kernels
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-beniget>=0.5.0:../../devel/py-beniget
DEPENDS+=	${PYPKGPREFIX}-gast>=0.7.0:../../devel/py-gast
DEPENDS+=	${PYPKGPREFIX}-numpy>=0:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-ply>=3.4:../../devel/py-ply
DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	pythran pythran-config

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
