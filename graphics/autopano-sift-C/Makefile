# $NetBSD: Makefile,v 1.29 2023/11/08 13:19:26 wiz Exp $

DISTNAME=	autopano-sift-C-2.5.1
PKGREVISION=	19
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hugin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hugin.sourceforge.net/
COMMENT=	SIFT Feature Detection implementation

LICENSE=	gnu-gpl-v2

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

LDFLAGS.DragonFly=	-lm
LDFLAGS.SunOS=		-lm

# work-around finding libpng
post-extract:
	rm ${WRKSRC}/CMakeModules/FindPNG.cmake

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/libpano13/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
