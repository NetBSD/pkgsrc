# $NetBSD: Makefile,v 1.3 2022/05/04 06:44:12 wiz Exp $

DISTNAME=	tomlplusplus-3.1.0
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
