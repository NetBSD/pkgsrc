# $NetBSD: Makefile,v 1.17 2024/11/11 07:27:51 wiz Exp $

DISTNAME=	libarchive-c-5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/libarchive-c/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Changaco/python-libarchive-c
COMMENT=	Python interface to libarchive
LICENSE=	cc0-1.0-universal

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
