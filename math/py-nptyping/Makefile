# $NetBSD: Makefile,v 1.6 2025/07/03 19:18:08 wiz Exp $

DISTNAME=	nptyping-2.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nptyping/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ramonhagenaars/nptyping
COMMENT=	Type hints for NumPy
LICENSE=	mit

# for pandas support
#DEPENDS+=		${PYPKGPREFIX}-pandas>=0:../../math/py-pandas
# unpackaged
#TOOL_DEPENDS+=	# TODO: pandas-stubs-fork;python_version>="3.8"

# unpackaged
#TEST_DEPENDS+=	# TODO: beartype>=0.10.0;python_version>='3.10'
TEST_DEPENDS+=	${PYPKGPREFIX}-feedparser>=0:../../textproc/py-feedparser
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>=0:../../lang/py-mypy
# unpackaged
#TEST_DEPENDS+=	# TODO: pyright>=0
TEST_DEPENDS+=	${PYPKGPREFIX}-typeguard>=0:../../devel/py-typeguard

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.20.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
