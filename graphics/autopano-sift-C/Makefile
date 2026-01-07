# $NetBSD: Makefile,v 1.39 2026/01/07 08:47:14 wiz Exp $

DISTNAME=	autopano-sift-C-2.5.1
PKGREVISION=	27
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hugin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hugin.sourceforge.net/
COMMENT=	SIFT Feature Detection implementation
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

LDFLAGS.DragonFly=	-lm
LDFLAGS.SunOS=		-lm

# work-around finding libpng
post-extract:
	rm ${WRKSRC}/CMakeModules/FindPNG.cmake

.include "../../devel/cmake/build.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/libpano13/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
