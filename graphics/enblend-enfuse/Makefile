# $NetBSD: Makefile,v 1.12 2012/09/14 14:38:12 obache Exp $

DISTNAME=	enblend-enfuse-4.0
# XXX distribution file has changed; remove the line below on next update
DIST_SUBDIR=	${PKGNAME_NOREV}
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=enblend/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://enblend.sourceforge.net/
COMMENT=	Combines overlapping images without seams, with good exposure
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}-753b534c819d

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl:build pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-image-cache

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--enable-openmp
CONFIGURE_ARGS+=	--with-apple-opengl-framework
.else
CONFIGURE_ARGS+=	--with-x
.include "../../graphics/glut/buildlink3.mk"
.endif

LIBS+=			-lboost_system

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libxmi/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
