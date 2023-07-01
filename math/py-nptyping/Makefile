# $NetBSD: Makefile,v 1.3 2023/07/01 08:37:39 wiz Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 38

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.0:../../devel/py-typing-extensions
.endif

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.20.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
