# $NetBSD: Makefile,v 1.5 2023/04/26 19:57:06 wiz Exp $

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

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
