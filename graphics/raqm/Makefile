# $NetBSD: Makefile,v 1.9 2026/09/02 19:02:54 wiz Exp $

DISTNAME=	raqm-0.11.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=HOST-Oman/}
GITHUB_PROJECT=	libraqm
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/HOST-Oman/libraqm
COMMENT=	Library for complex text layout
LICENSE=	mit

USE_TOOLS+=	pkg-config

CPPFLAGS.SunOS+=	-D__EXTENSIONS__

PKGCONFIG_OVERRIDE+=		output/meson-private/raqm.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
