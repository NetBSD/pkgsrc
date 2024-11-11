# $NetBSD: Makefile,v 1.39 2024/11/11 07:27:51 wiz Exp $

DISTNAME=	lz4-4.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lz4/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-lz4/python-lz4
COMMENT=	Python LZ4 binding
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-pkgconfig-[0-9]*:../../devel/py-pkgconfig
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=45:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

# build 'stream'
MAKE_ENV+=	PYLZ4_EXPERIMENTAL=1

USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../archivers/lz4/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
