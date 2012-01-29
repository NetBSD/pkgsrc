# $NetBSD: Makefile,v 1.10 2012/01/29 21:07:12 marino Exp $

DISTNAME=	autopano-sift-C-2.5.1
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hugin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hugin.sourceforge.net/
COMMENT=	SIFT Feature Detection implementation

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

LDFLAGS.DragonFly=	-lm

# work-around finding libpng
post-extract:
	rm ${WRKSRC}/CMakeModules/FindPNG.cmake

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/libpano13/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
