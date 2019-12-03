# $NetBSD: Makefile,v 1.9 2019/12/03 16:41:21 adam Exp $

DISTNAME=	importlib_metadata-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/importlib-metadata/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://importlib-metadata.readthedocs.io/
COMMENT=	Read metadata from Python packages
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-zipp>=0.5:../../archivers/py-zipp
.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-configparser>=3.5:../../devel/py-configparser
DEPENDS+=	${PYPKGPREFIX}-contextlib2-[0-9]*:../../devel/py-contextlib2
DEPENDS+=	${PYPKGPREFIX}-pathlib2-[0-9]*:../../devel/py-pathlib2
.endif

USE_LANGUAGES=	# none

xx-post-extract:
	cd ${WRKSRC} && ${FIND} . -xdev -type f -exec chmod go-w {} +

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
