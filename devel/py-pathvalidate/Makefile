# $NetBSD: Makefile,v 1.8 2025/01/04 06:38:28 adam Exp $

DISTNAME=	pathvalidate-3.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pathvalidate/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/thombashi/pathvalidate
COMMENT=	Python library to sanitize/validate a string such as filenames
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=64:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-allpairspy>=2:../../devel/py-allpairspy
TEST_DEPENDS+=	${PYPKGPREFIX}-click>=6.2:../../devel/py-click
TEST_DEPENDS+=	${PYPKGPREFIX}-faker>=1.0.8:../../devel/py-faker

USE_LANGUAGES=	# none
USE_TOOLS+=	pkg-config

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
