# $NetBSD: Makefile,v 1.102 2003/09/17 19:49:24 grant Exp $

.include "Makefile.common"

PKGNAME=		ImageMagick-${DISTVERSION}

CATEGORIES=		graphics

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.simplesystems.org/ImageMagick/
COMMENT=		Package for display and interactive manipulation of images

DEPENDS+=		mpeg2codec-1.2:../../graphics/mpeg2codec

CONFLICTS=		geomview<1.8.1nb2  # used to have a program named 'animate'

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GCC_REQD=		2.95.3

PLIST_SUBST+=		IM_MAJOR_VER=${IM_MAJOR_VER}
PLIST_SUBST+=		IM_MAJOR_LIB_VER=${IM_MAJOR_LIB_VER}

.include "../../mk/bsd.prefs.mk"

# c++ broken as of 'gcc version 2.95.3 20010315 (release) (NetBSD nb1)'
NOT_FOR_PLATFORM=	NetBSD-*-sparc64

# Avoid compiler bug on "mipsel" (cobalt?)
.if (${MACHINE_ARCH} == mipsel)
CFLAGS=			-O
.endif

# Some configure_args come from Makefile.common
CONFIGURE_ARGS+=	--without-perl

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../graphics/jasper/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
