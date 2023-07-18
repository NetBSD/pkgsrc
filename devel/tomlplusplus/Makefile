# $NetBSD: Makefile,v 1.8 2023/07/18 14:11:17 nia Exp $

DISTNAME=	tomlplusplus-3.3.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=marzer/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://marzer.github.io/tomlplusplus/
COMMENT=	TOML library for c++
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
MESON_ARGS+=	--datadir=lib

USE_CXX_FEATURES+=	c++17

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
