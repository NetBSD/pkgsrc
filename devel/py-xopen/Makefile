# $NetBSD: Makefile,v 1.34 2025/02/13 13:50:00 adam Exp $

DISTNAME=	xopen-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xopen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pycompression/xopen
COMMENT=	Open compressed files transparently
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
DEPENDS+=	pbzip2-[0-9]*:../../archivers/pbzip2
DEPENDS+=	pigz-[0-9]*:../../archivers/pigz
DEPENDS+=	xz-[0-9]*:../../archivers/xz
DEPENDS+=	${PYPKGPREFIX}-zlib-ng>=0.4.1:../../archivers/py-zlib-ng
DEPENDS+=	${PYPKGPREFIX}-zstandard-[0-9]*:../../archivers/py-zstandard
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
