# $NetBSD: Makefile,v 1.11 2019/06/08 11:04:29 rillig Exp $

VERSION=	1.3.1
DISTNAME=	gdspy-${VERSION}
PKGNAME=	${PYPKGPREFIX}-gds-${VERSION}
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
