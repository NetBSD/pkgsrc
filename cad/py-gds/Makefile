# $NetBSD: Makefile,v 1.4 2016/09/19 06:13:35 mef Exp $

VERSION=	1.0
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

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"

.include "../../mk/bsd.pkg.mk"
