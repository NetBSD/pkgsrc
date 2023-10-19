# $NetBSD: Makefile,v 1.9 2023/10/19 13:10:19 wiz Exp $

DISTNAME=	tomlplusplus-3.4.0
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
