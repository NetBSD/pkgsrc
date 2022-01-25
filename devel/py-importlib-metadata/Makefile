# $NetBSD: Makefile,v 1.25 2022/01/25 09:19:29 wiz Exp $

DISTNAME=	importlib_metadata-4.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/importlib-metadata/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://importlib-metadata.readthedocs.io/
COMMENT=	Read metadata from Python packages
LICENSE=	apache-2.0

#DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-zipp-[0-9]*:../../archivers/py-zipp
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-fakefs-[0-9]*:../../devel/py-fakefs
TEST_DEPENDS+=	${PYPKGPREFIX}-pep517-[0-9]*:../../devel/py-pep517

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${_PYTHON_VERSION} < 38
TEST_DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.6.4:../../devel/py-typing-extensions
.endif

USE_LANGUAGES=	# none

post-extract:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} go-w {} +

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
