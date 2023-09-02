# $NetBSD: Makefile,v 1.1 2023/09/02 18:16:57 bsiegert Exp $

DISTNAME=	nuspell-5.1.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=nuspell/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://nuspell.github.io/
COMMENT=	Free and Open Source C++ spell checking library
LICENSE=	gnu-lgpl-v3

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++17

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=1 -DCMAKE_BUILD_TYPE=Release

PKGCONFIG_OVERRIDE+=	nuspell.pc.in

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/catch2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
