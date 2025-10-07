# $NetBSD: Makefile,v 1.3 2025/10/07 09:02:53 adam Exp $

DISTNAME=	zlib_ng-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zlib-ng/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pycompression/python-zlib-ng
COMMENT=	Drop-in replacement for zlib and gzip modules using zlib-ng
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm

MAKE_ENV+=	PYTHON_ZLIB_NG_LINK_DYNAMIC=1

.include "../../archivers/zlib-ng/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
