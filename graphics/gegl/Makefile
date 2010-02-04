# $NetBSD: Makefile,v 1.10 2010/02/04 12:28:43 adam Exp $

DISTNAME=	gegl-0.1.0
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gegl/0.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gegl.org/
COMMENT=	Graph based image processing framework

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_path_ASCIIDOC=no
CONFIGURE_ENV+=		ac_cv_path_ENSCRIPT=no
CONFIGURE_ENV+=		ac_cv_path_SDL_CONFIG=no
CONFIGURE_ENV+=		ac_cv_prog_RUBY=no

PKGCONFIG_OVERRIDE+=	gegl.pc.in

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	v4l

.if ${OPSYS} == "Linux" && exists(/usr/include/linux/videodev.h)
PLIST.v4l=	yes
.endif

.include "options.mk"

.include "../../graphics/babl/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
