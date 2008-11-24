# $NetBSD: Makefile,v 1.46.8.2 2008/11/24 08:43:51 rtr Exp $

DISTNAME=	imlib2-1.4.2
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://docs.enlightenment.org/api/imlib2/html/
COMMENT=	Image manipulation library

PKG_DESTDIR_SUPPORT=	user-destdir

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

SUBST_CLASSES+=		shlib
SUBST_STAGE.shlib=	post-patch
SUBST_MESSAGE.shlib=	Replacing shared library suffix
SUBST_FILES.shlib+=	src/lib/image.c
SUBST_SED.shlib+=	-e 's,"\.so",".${SHLIB_SUFFIX}",'

.include "options.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
