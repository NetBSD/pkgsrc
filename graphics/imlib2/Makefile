# $NetBSD: Makefile,v 1.68 2013/12/23 11:57:04 wiz Exp $

DISTNAME=	imlib2-1.4.5
PKGREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=enlightenment/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docs.enlightenment.org/api/imlib2/html/
COMMENT=	Image manipulation library

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

PKGCONFIG_OVERRIDE=	imlib2.pc.in

LIBS.SunOS+=		-lm

.include "../../mk/bsd.prefs.mk"

.if ${OBJECT_FMT} == "SOM"
SHLIB_SUFFIX=		sl
.else
SHLIB_SUFFIX=		so
.endif

SUBST_CLASSES+=		shlib rpath
SUBST_STAGE.shlib=	post-patch
SUBST_MESSAGE.shlib=	Replacing shared library suffix
SUBST_FILES.shlib+=	src/lib/image.c
SUBST_SED.shlib+=	-e 's,"\.so",".${SHLIB_SUFFIX}",'

SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Replacing COMPILER_RPATH_FLAG
SUBST_FILES.rpath=	imlib2-config.in
SUBST_VARS.rpath=	COMPILER_RPATH_FLAG

.include "options.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
