# $NetBSD: Makefile,v 1.116 2004/04/24 04:39:30 reed Exp $

.include "Makefile.common"

PKGNAME=	ImageMagick-${DISTVERSION}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.simplesystems.org/ImageMagick/
COMMENT=	Package for display and interactive manipulation of images

BUILDLINK_DEPENDS.jasper+=	jasper>=1.701.0
DEPENDS+=			mpeg2codec-1.2:../../graphics/mpeg2codec

CONFLICTS=	geomview<1.8.1nb2  # used to have a program named 'animate'

USE_BUILDLINK3=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE=	Magick++/lib/ImageMagick++.pc.in
PKGCONFIG_OVERRIDE+=	magick/ImageMagick.pc.in

GCC_REQD+=		2.95.3

PLIST_SUBST+=		IM_MAJOR_VER=${IM_MAJOR_VER}
PLIST_SUBST+=		IM_MAJOR_LIB_VER=${IM_MAJOR_LIB_VER}

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-sparc64)
GCC_REQD+=		3.0
.endif

# Avoid compiler bug on "mipsel" (cobalt?)
.if ${MACHINE_ARCH} == "mipsel"
CFLAGS=			-O
.endif

# Some configure_args come from Makefile.common
CONFIGURE_ARGS+=	--without-perl

# Remove the empty directory
post-install:
	-${RMDIR} ${PREFIX}/share/ImageMagick

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
