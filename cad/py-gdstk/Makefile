# $NetBSD: Makefile,v 1.12 2024/02/23 09:39:17 mef Exp $

VERSION=	0.9.50
GITHUB_TAG=	v${VERSION}
DISTNAME=	gdstk-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=heitzmann/}
GITHUB_PROJECT=	gdstk

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/heitzmann/gdstk/
COMMENT=	C++ library for GDSII and OASIS files
LICENSE=	boost-license

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES+=	c c++
USE_TOOLS+=	cmake

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../devel/zlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../math/qhull/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
