# $NetBSD: Makefile,v 1.1 2022/06/17 11:38:30 mef Exp $

VERSION=	0.8.3
GITHUB_TAG=	v${VERSION}
DISTNAME=	gdstk-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=heitzmann/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/heitzmann/gdstk/
COMMENT=	C++ library for GDSII and OASIS files
LICENSE=	boost-license

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES+=	c c++
USE_TOOLS+=	cmake

PYTHON_VERSIONS_INCOMPATIBLE=	27 37

.include "../../devel/zlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
