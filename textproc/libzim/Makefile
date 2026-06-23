# $NetBSD: Makefile,v 1.9 2026/06/23 10:32:12 wiz Exp $

DISTNAME=	libzim-9.8.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=openzim/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/openzim/libzim/
COMMENT=	Reference implementation of the ZIM specification
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=		output/meson-private/libzim.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

.include "../../lang/python/tool.mk"
.include "../../devel/meson/build.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
