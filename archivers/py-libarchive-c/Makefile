# $NetBSD: Makefile,v 1.12 2018/06/15 08:08:18 adam Exp $

DISTNAME=	libarchive-c-2.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/libarchive-c/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Changaco/python-libarchive-c
COMMENT=	Python interface to libarchive
LICENSE=	cc0-1.0-universal

USE_LANGUAGES=	# none

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
