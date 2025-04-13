# $NetBSD: Makefile,v 1.19 2025/04/13 08:06:23 adam Exp $

DISTNAME=	libarchive_c-5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/libarchive-c/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Changaco/python-libarchive-c
COMMENT=	Python interface to libarchive
LICENSE=	cc0-1.0-universal

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
