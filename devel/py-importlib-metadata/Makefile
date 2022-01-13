# $NetBSD: Makefile,v 1.24 2022/01/13 19:31:23 wiz Exp $

DISTNAME=	importlib_metadata-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/importlib-metadata/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://importlib-metadata.readthedocs.io/
COMMENT=	Read metadata from Python packages
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-fakefs-[0-9]*:../../devel/py-fakefs
TEST_DEPENDS+=	${PYPKGPREFIX}-pep517-[0-9]*:../../devel/py-pep517
.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-configparser>=3.5:../../devel/py-configparser
DEPENDS+=	${PYPKGPREFIX}-contextlib2-[0-9]*:../../devel/py-contextlib2
DEPENDS+=	${PYPKGPREFIX}-pathlib2-[0-9]*:../../devel/py-pathlib2
.endif
.if ${_PYTHON_VERSION} < 39
TEST_DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=1.3:../../devel/py-importlib-resources
.endif

PYTHON_VERSIONED_DEPENDENCIES+=	packaging zipp setuptools_scm:build

USE_LANGUAGES=	# none

post-extract:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} go-w {} +

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
