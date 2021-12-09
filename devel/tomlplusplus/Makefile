# $NetBSD: Makefile,v 1.1 2021/12/09 16:28:33 wiz Exp $

DISTNAME=	tomlplusplus-2.5.0
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
