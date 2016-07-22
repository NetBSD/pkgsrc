# $NetBSD: Makefile,v 1.2 2016/07/22 00:21:23 mef Exp $

VERSION=	0.9
DISTNAME=	gdspy-${VERSION}
PKGNAME=        ${PYPKGPREFIX}-gds-${VERSION}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=heitzmann/}
GITHUB_PROJECT=	gdspy
GITHUB_TAG=	v${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/heitzmann/gdspy
COMMENT=	Python module for creating GDSII stream files
LICENSE=	gnu-gpl-v3

USE_LANGUAGES+=	c c++

DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy

PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
