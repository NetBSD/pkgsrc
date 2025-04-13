# $NetBSD: Makefile,v 1.2 2025/04/13 08:06:23 adam Exp $

DISTNAME=	zlib_ng-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zlib-ng/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pycompression/python-zlib-ng
COMMENT=	Drop-in replacement for zlib and gzip modules using zlib-ng
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-versioningit>=1.1.0:../../devel/py-versioningit

MAKE_ENV+=	PYTHON_ZLIB_NG_LINK_DYNAMIC=1

.include "../../archivers/zlib-ng/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
