# $NetBSD: Makefile,v 1.93 2024/09/16 07:20:15 adam Exp $

DISTNAME=	imlib2-1.12.2
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=enlightenment/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.enlightenment.org/api/imlib2/html/
COMMENT=	Image manipulation library
LICENSE=	mit	# with some modifications

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gif
CONFIGURE_ARGS+=	--with-jpeg
CONFIGURE_ARGS+=	--without-j2k
CONFIGURE_ARGS+=	--without-jxl
CONFIGURE_ARGS+=	--with-png
CONFIGURE_ARGS+=	--without-ps
CONFIGURE_ARGS+=	--without-raw
CONFIGURE_ARGS+=	--without-svg
CONFIGURE_ARGS+=	--with-tiff
CONFIGURE_ARGS+=	--without-y4m
CONFIGURE_ARGS+=	--with-bz2
CONFIGURE_ARGS+=	--with-lzma
CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--without-id3

PKGCONFIG_OVERRIDE=	imlib2.pc.in

LIBS.SunOS+=		-lm

.include "../../mk/bsd.prefs.mk"

.if ${OBJECT_FMT} == "SOM"
SHLIB_SUFFIX=		sl
.else
SHLIB_SUFFIX=		so
.endif

.if ${SHLIB_SUFFIX} != so
SUBST_CLASSES+=		shlib
SUBST_STAGE.shlib=	pre-configure
SUBST_MESSAGE.shlib=	Replacing shared library suffix
SUBST_FILES.shlib+=	src/lib/image.c
SUBST_SED.shlib+=	-e 's,"\.so",".${SHLIB_SUFFIX}",'
.endif

.include "options.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
