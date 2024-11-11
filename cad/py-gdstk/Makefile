# $NetBSD: Makefile,v 1.16 2024/11/11 07:27:53 wiz Exp $

DISTNAME=	gdstk-0.9.50
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_GITHUB:=heitzmann/}
GITHUB_PROJECT=	gdstk
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/heitzmann/gdstk/
COMMENT=	C++/Python library for GDSII and OASIS files
LICENSE=	boost-license

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES+=	c c++
USE_TOOLS+=	cmake

.include "../../devel/zlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../math/qhull/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
