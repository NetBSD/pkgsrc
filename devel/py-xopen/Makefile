# $NetBSD: Makefile,v 1.36 2026/09/03 08:31:11 adam Exp $

DISTNAME=	xopen-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xopen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pycompression/xopen
COMMENT=	Open compressed files transparently
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
DEPENDS+=	pbzip2>=0:../../archivers/pbzip2
DEPENDS+=	pigz>=0:../../archivers/pigz
DEPENDS+=	xz>=0:../../archivers/xz
DEPENDS+=	${PYPKGPREFIX}-zlib-ng>=0.4.1:../../archivers/py-zlib-ng
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=0:../../devel/py-test-timeout

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 314
DEPENDS+=	${PYPKGPREFIX}-backports.zstd>=0:../../archivers/py-backports.zstd
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
