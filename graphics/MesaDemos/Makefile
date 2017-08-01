# $NetBSD: Makefile,v 1.41 2017/08/01 14:58:59 wiz Exp $

DISTNAME=	mesa-demos-8.2.0
PKGNAME=	${DISTNAME:S/mesa-demos/MesaDemos/}
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/demos/8.2.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cgit.freedesktop.org/mesa/demos/
COMMENT=	OpenGL examples and Demos
#LICENSE=	# Similar to mit but with SGI advertising clause.

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

SUBST_CLASSES+=		bitmap
SUBST_STAGE.bitmap=	pre-configure
SUBST_MESSAGE.bitmap=	Avoid conflict with x11/bitmap and graphics/glx-utils
SUBST_FILES.bitmap=	src/glsl/Makefile.in
SUBST_FILES.bitmap+=	src/xdemos/Makefile.in
SUBST_SED.bitmap=	-e 's/bitmap$$(EXEEXT)/bitmap_mesademos$$(EXEEXT)/g'
SUBST_SED.bitmap+=	-e 's/glxgears$$(EXEEXT)/glxgears_mesademos$$(EXEEXT)/g'
SUBST_SED.bitmap+=	-e 's/glxinfo$$(EXEEXT)/glxinfo_mesademos$$(EXEEXT)/g'

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
