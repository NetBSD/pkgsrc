# $NetBSD: Makefile,v 1.1 2022/01/25 08:55:50 wiz Exp $

DISTNAME=	importlib_metadata-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/importlib-metadata/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://importlib-metadata.readthedocs.io/
COMMENT=	Read metadata from Python packages (python 2.x)
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-configparser>=3.5:../../devel/py-configparser
DEPENDS+=	${PYPKGPREFIX}-contextlib2-[0-9]*:../../devel/py-contextlib2
DEPENDS+=	${PYPKGPREFIX}-pathlib2-[0-9]*:../../devel/py-pathlib2
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging2
DEPENDS+=	${PYPKGPREFIX}-zipp-[0-9]*:../../archivers/py-zipp1
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm5
TEST_DEPENDS+=	${PYPKGPREFIX}-fakefs-[0-9]*:../../devel/py-fakefs
TEST_DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=1.3:../../devel/py-importlib-resources
TEST_DEPENDS+=	${PYPKGPREFIX}-pep517-[0-9]*:../../devel/py-pep517

PYTHON_VERSIONS_ACCEPTED=	27

USE_LANGUAGES=	# none

post-extract:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} go-w {} +

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
