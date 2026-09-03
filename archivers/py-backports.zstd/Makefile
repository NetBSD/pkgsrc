# $NetBSD: Makefile,v 1.1 2026/09/03 08:25:04 adam Exp $

DISTNAME=	backports_zstd-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/backports.zstd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rogdham/backports.zstd
COMMENT=	Backport of compression.zstd
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=80:../../devel/py-setuptools

WHEEL_ARGS+=	-C=--system-zstd=1
#WHEEL_ARGS+=	--system-zstd

PYTHON_VERSIONS_ACCEPTED=	313 312 311 310 # included in 3.14+

.include "../../archivers/zstd/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
