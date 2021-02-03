# $NetBSD: Makefile,v 1.1 2021/02/03 10:28:41 nia Exp $

DISTNAME=	inih-r52
PKGNAME=	${DISTNAME:S/-r/-/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=benhoyt/}
GITHUB_PROJECT=	inih
GITHUB_TAG=	r${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/benhoyt/inih
COMMENT=	Simple .INI file parser in C
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

MESON_ARGS+=	-Ddefault_library=shared
MESON_ARGS+=	-Ddistro_install=true
MESON_ARGS+=	-Dwith_INIReader=true

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/inih.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/INIReader.pc

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
