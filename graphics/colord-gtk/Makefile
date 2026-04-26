# $NetBSD: Makefile,v 1.21 2026/04/26 16:55:31 vins Exp $

DISTNAME=	colord-gtk-0.3.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=hughsie/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/software/colord/
COMMENT=	Manage color profiles to accurately color input/output devices
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config xgettext

USE_PKGLOCALEDIR=	yes

PYTHON_FOR_BUILD_ONLY=	tool

MESON_ARGS+=	-Dman=false

.include "options.mk"

PKGCONFIG_OVERRIDE_STAGE=	pre-install

.include "../../devel/meson/build.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/colord/buildlink3.mk"
.include "../../textproc/libxslt/xsltproc-nonet.mk"
.include "../../mk/bsd.pkg.mk"
