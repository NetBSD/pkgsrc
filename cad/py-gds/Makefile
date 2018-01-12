# $NetBSD: Makefile,v 1.9 2018/01/12 12:55:50 mef Exp $

VERSION=	1.2.1
DISTNAME=	gdspy-${VERSION}
PKGNAME=        ${PYPKGPREFIX}-gds-${VERSION}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=heitzmann/}
GITHUB_PROJECT=	gdspy
GITHUB_TAG=	v${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/heitzmann/gdspy
COMMENT=	Python module for creating GDSII stream files
LICENSE=	boost-license

USE_LANGUAGES+=	c c++

DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy

.include "../../lang/python/egg.mk"

.include "../../mk/bsd.pkg.mk"
